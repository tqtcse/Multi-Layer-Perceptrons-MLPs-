/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   dataloader.h
 * Author: ltsach
 *
 * Created on September 2, 2024, 4:01 PM
 */

#ifndef DATALOADER_H
#define DATALOADER_H
#include "loader/dataset.h"
#include "tensor/xtensor_lib.h"

using namespace std;

template<typename DType, typename LType>
class DataLoader{
public:
    class Iterator;
private:
    Dataset<DType, LType>* ptr_dataset;
    int batch_size;
    bool shuffle;
    bool drop_last;
    vector<int> ind;
    int m_seed;
    /*TODO: add more member variables to support the iteration*/
public:
    DataLoader(Dataset<DType, LType>* ptr_dataset,
            int batch_size,
            bool shuffle=true,
            bool drop_last=false,
            int seed = -1){
        /*TODO: Add your code to do the initialization */
        this->ptr_dataset = ptr_dataset;
        this->batch_size = batch_size;
        this->shuffle = shuffle;
        this->drop_last = drop_last;
        // if(this->batch_size > ptr_dataset->len() && drop_last == false){
        //     this->batch_size = ptr_dataset->len();
        // }
        this->m_seed = seed;
        ind.resize(ptr_dataset->len());
        iota(ind.begin(), ind.end(), 0);

        if(shuffle && seed >= 0){
            shuff(seed);
        }

    }
    virtual ~DataLoader(){}
    //New method: from V2: begin
    int get_batch_size(){ return batch_size; }
    int get_sample_count(){ return ptr_dataset->len(); }
    int get_total_batch(){return int(ptr_dataset->len()/batch_size); }
    
    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// START: Section                                                     //
    /////////////////////////////////////////////////////////////////////////
    void shuff(int seed){
        xt::xarray<int> index = xt::adapt(ind);
        xt::random::seed(seed);
        xt::random::shuffle(index);
        ind.assign(index.data(), index.data() + index.size());
    }

    Iterator begin(){
        // if(shuffle){
        //     shuff();
        // }
        return Iterator(*this, 0);
        // if(ptr_dataset->len() > 0){
        //     return Iterator(*this, 0);
        // }else{
        //     return Iterator(*this, ptr_dataset->len());
        // }
    }

    Iterator end(){
        return Iterator(*this, ptr_dataset->len());
    }

    class Iterator{
    private:
        int index;
        DataLoader<DType, LType>& loader;
        int current_index;
        bool end;
    public:
        Iterator(DataLoader<DType, LType>& loader, int index) : loader(loader), index(index), current_index(0), end(false) {}

        // Iterator& operator=(const Iterator& r){
        //     if(this != &r){
        //         loader = r.loader;
        //         index = r.index;
        //     }
        //     return *this;
        // }
        
        Iterator& operator++(){
            ++index;
            if(current_index >= loader.ptr_dataset->len()){
                end = true;
            }
            current_index += loader.batch_size;
            return *this;
        }

        Iterator operator++(int){
            Iterator iterator = *this;
            current_index += loader.batch_size;
            return iterator;
        }

        bool operator!=(const Iterator& o) const{
            if(current_index + loader.batch_size > loader.ptr_dataset->len()){
                return end;
            }
            return !end;
        }

        Batch<DType, LType> operator*() const{
            bool is_batch_end = false;

            auto shape = loader.ptr_dataset->get_data_shape();
            auto label = loader.ptr_dataset->get_label_shape();
            // cout << "num in data: " << shape.data()[0] << endl; // so luong phan tu data
            // cout << "num in label: "<< label.data()[0] << endl;

            /* Xu ly phan du*/

            int k = shape.data()[0];
            int batch_cuoi = 0;
            int co_du_khong = k%loader.batch_size;
            // cout << "Co du khong: " << co_du_khong << endl;
            if(co_du_khong != 0){
                if(loader.drop_last == false){
                    batch_cuoi = co_du_khong;
                    batch_cuoi = loader.batch_size + co_du_khong;
                }
            }
            shape[0] = loader.batch_size;
            label[0] = loader.batch_size;
            size_t sizeD = shape.size();
            // cout << "Data size: " << sizeD << endl;
            size_t sizeL = label.size();
            // cout << "Label size: " << sizeL << endl;

            
            vector<size_t> data_shape(sizeD);
            for(size_t i = 0; i < sizeD; i++){
                data_shape[i] = shape[i];
            }
            // cout << "Data shape: " << xt::adapt(data_shape) << endl;

            vector<size_t> label_shape(sizeL);
            for(size_t j = 0; j < sizeL; j++){
                label_shape[j] = label[j];
            }
            // cout << "Label shape: " << xt::adapt(label_shape) << endl;

            if(loader.drop_last == false){
                if(current_index + batch_cuoi > current_index + loader.batch_size
                && current_index + batch_cuoi >= loader.ptr_dataset->len()){
                    is_batch_end = true;
                    if(sizeD != 0){
                        data_shape[0] = batch_cuoi;
                    }
                    if(sizeL != 0){
                        label_shape[0] = batch_cuoi;
                    }
                }
            }

            xt::xarray<DType> Batch_data;
            xt::xarray<LType> Batch_label;
            if (std::is_same<DType, std::string>::value) {
                Batch_data = xt::empty<DType>(data_shape);
            } else {
                Batch_data = xt::zeros<DType>(data_shape);
            }
            if (std::is_same<LType, std::string>::value) {
                Batch_label = xt::empty<LType>(label_shape);
            } else {
                Batch_label = xt::zeros<LType>(label_shape);
            }

            // cout << xt::adapt(Batch_data.shape()) << endl;
            // cout << xt::adapt(Batch_label.shape()) << endl;
            if(is_batch_end == true){
                for(size_t i = current_index; i < current_index + batch_cuoi; i++){
                    int i_after_shuff = loader.ind[i];
                    auto item = loader.ptr_dataset->getitem(i_after_shuff);
                    if(sizeD != 0){
                        auto batch_view1 = xt::view(Batch_data, i - current_index, xt::all());
                        batch_view1 = item.getData();
                    }
                    if(sizeL != 0){
                        auto batch_view2 = xt::view(Batch_label, i - current_index, xt::all());
                        batch_view2 = item.getLabel();
                    }
                }
            }else{
                for(size_t i = current_index; i < current_index + loader.batch_size; i++){
                    int i_after_shuff = loader.ind[i];
                    auto item = loader.ptr_dataset->getitem(i_after_shuff);
                    if(sizeD != 0){
                        auto batch_view1 = xt::view(Batch_data, i - current_index, xt::all());
                        batch_view1 = item.getData();
                    }
                    if(sizeL != 0){
                        auto batch_view2 = xt::view(Batch_label, i - current_index, xt::all());
                        batch_view2 = item.getLabel();
                    }
                }
            }
            


            // cout << "asdasdas" << endl;
            return Batch<DType, LType>(Batch_data, Batch_label);
        }
            
    };


    /*TODO: Add your code here to support iteration on batch*/
    
    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// END: Section                                                       //
    /////////////////////////////////////////////////////////////////////////
};


#endif /* DATALOADER_H */


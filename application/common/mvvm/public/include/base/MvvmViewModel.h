/**
 * @file MvvmViewModel.h
 * @author Lisaro (lli747723@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MVVM_VIEW_MODEL_H
#define MVVM_VIEW_MODEL_H

// viewmodel.h
#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "model.h"
#include "lvgl.h"

class ViewModel {
public:
    ViewModel(Model& model ,view& view) : _model(model) _view(view){}

    // 页面生命周期管理
    void onPageLoad() {
        // 页面加载时初始化逻辑
    }

    void onPageUnload() {
        // 页面卸载时清理逻辑
    }

    // 更新数据
    void updateModel(int newData) {
        _model.setData(newData);
    }

    int getModelData() const {
        return _model.getData();
    }

    // 事件处理
    void onClicked(lv_event_t* event) {
        // 点击事件处理逻辑
        updateModel(getModelData() + 1); // 点击后更新Model数据
    }

    void onScroll(lv_event_t* event) {
        // 滚动事件处理逻辑
    }

    void onScrollEnd(lv_event_t* event) {
        // 滚动结束事件处理逻辑
    }

    void onGesture(lv_event_t* event) {
        // 手势事件处理逻辑
    }

private:
    Model& _model;
    View& _view;
}

#endif // MVVM_VIEW_MODEL_H

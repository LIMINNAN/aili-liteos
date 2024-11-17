/**
 * @file MvvmViewModel.cpp
 * @author Lisaro (lli747723@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-09-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "MvvmViewModel.h"

MvvmViewModel::MvvmViewModel(MvvmModel *model, MvvmView *view) : model_(model), view_(view) {}

void MvvmViewModel::updateModel(const std::string &data) {
    model_->setData(data);
    notifyView();
}

void MvvmViewModel::notifyView() { view_->updateView(*model_); }

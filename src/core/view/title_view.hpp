#pragma once
#include "IView.hpp"
namespace tysm {

class TitleView : public IView {
public:
    TitleView() = default;
    void show() override;
};

} // namespace tysm

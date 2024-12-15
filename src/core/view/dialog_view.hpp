#pragma once
#include "view/IView.hpp"
namespace tysm {
class DialogView : public IView {
public:
    DialogView() = default;
    void show() override;
};
} // namespace tysm

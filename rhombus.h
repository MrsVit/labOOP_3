#include "figure.h"

class Rhombus : public Figure
{
public:
    Rhombus();
    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;

    virtual void Print(std::ostream& os) const override;
    virtual void Read(std::istream& is) override;

    virtual Point Center() const override;
    virtual double Area() const override;

    virtual operator double() const override;

    bool operator==(const Rhombus& other) const = default;
    virtual bool operator==(const Figure& other) const override;
    ~Rhombus();

private:
    Point* points{nullptr};
    int count{4};
};

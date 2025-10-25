#include "figure.h"

class Sixsquere : public Figure
{
public:
    Sixsquere();
    Sixsquere(const Sixsquere& other);
    Sixsquere(Sixsquere&& other) noexcept;
    Sixsquere& operator=(const Sixsquere& other);
    Sixsquere& operator=(Sixsquere&& other) noexcept;

    virtual void Print(std::ostream& os) const override;
    virtual void Read(std::istream& is) override;
    virtual Point Center() const override;
    virtual double Area() const override;

    virtual operator double() const override;
    virtual bool operator==(const Figure& other) const override;
    ~Sixsquere();

private:
    Point* points{nullptr};
    int count{5};
};


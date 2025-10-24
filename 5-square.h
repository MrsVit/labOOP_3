#include "figure.h"

class Fivesquere : public Figure
{
public:
    Fivesquere();
    Fivesquere(const Fivesquere& other);
    Fivesquere(Fivesquere&& other) noexcept;
    Fivesquere& operator=(const Fivesquere& other);
    Fivesquere& operator=(Fivesquere&& other) noexcept;

    virtual void Print(std::ostream& os) const override;
    virtual void Read(std::istream& is) override;

    virtual Point Center() const override;
    virtual double Area() const override;

    virtual operator double() const override;
    virtual bool operator==(const Figure& other) const override;
    ~Fivesquere();

private:
    Point* points{nullptr};
    int count{5};
};

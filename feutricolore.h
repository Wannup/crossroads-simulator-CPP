#ifndef FEUTRICOLORE_H
#define FEUTRICOLORE_H

class FeuTricolore
{
public:
    FeuTricolore();
    FeuTricolore(bool state, int frequencyChange);
private:
    bool state;     // false -> red - true -> green
    int frequencyChange;
};

#endif // FEUTRICOLORE_H

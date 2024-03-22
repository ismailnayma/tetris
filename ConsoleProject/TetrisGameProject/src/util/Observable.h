#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>

// forward declaration
class Observer;

class Observable
{
public:
    virtual ~Observable() = default;
    void registerObserver(Observer * observer);
    void unregisterObserver(Observer * observer);
    void notifyObservers() const;

private:
    std::set<Observer *> _observers;
};


#endif // OBSERVABLE_H

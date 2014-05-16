#ifndef TABLEAUDEUXDIMENSION_H
#define TABLEAUDEUXDIMENSION_H

template<class T>
class tableauDeuxDimension {

public:
    tableauDeuxDimension();
    tableauDeuxDimension(int , int);
    void addItem(T, int, int);
    T getItem(int, int);
    ~tableauDeuxDimension();

private:
    T ** tableau;
    int width;
    int height;

};

template<class T>
tableauDeuxDimension<T>::tableauDeuxDimension() {
    //tableau = NULL;
}

template<class T>
tableauDeuxDimension<T>::tableauDeuxDimension(int w, int h) {
    width = w;
    height = h;
    tableau = new T*[width];
    for (int i = 0 ; i < width ; i++) {
        tableau[i] = new T[height];
    }

}

template<class T>
void tableauDeuxDimension<T>::addItem(T item, int i, int j) {
    if (i >= width) {
        T** newTableau;
        newTableau = new T*[i+1];
        if (j >= height) {
            for (int k = 0 ; k <= i ; k++) {
                newTableau[k] = new T[j+1];
            }
            for (int k = 0 ; k < width ; k++) {
                for (int l = 0 ; l < height ; l++) {
                    newTableau[k][l] = tableau[k][l];
                }
            }
            height = j+1;
        } else {
            for (int k = 0 ; k <= i ; k++) {
                newTableau[k] = new T[height];
            }
            for (int k = 0 ; k < width ; k++) {
                for (int l = 0 ; l < height ; l++) {
                    newTableau[k][l] = tableau[k][l];
                }
            }
        }
        tableau = newTableau;
        width = i+1;
    } else if (j >= height) {
        T** newTableau;
        newTableau = new T*[width];
        for (int k = 0 ; k < width ; k++) {
            newTableau[k] = new T[j+1];
        }
        for (int k = 0 ; k < width ; k++) {
            for (int l = 0 ; l < height ; l++) {
                newTableau[k][l] = tableau[k][l];
            }
        }
        height = j+1;
        tableau = newTableau;
    }
    tableau[i][j] = item;
}

template<class T>
T tableauDeuxDimension<T>::getItem(int i, int j) {
    return tableau[i][j];
}

template<class T>
tableauDeuxDimension<T>::~tableauDeuxDimension() {
    for (int i = 0 ; i < width ; i++) {
        for (int j = 0 ; j < height ; j++) {
            delete tableau[i][j];
        }
    }
}

#endif // TABLEAUDEUXDIMENSION_H

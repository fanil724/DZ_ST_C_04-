#ifndef MATRIX_H
#define MATRIX_H

#include <random>
#include <iomanip>
#include <ctime>

template<typename T>
class Matrix {
public:

    Matrix(size_t size1, size_t size2) {
        Rows = size1;
        Cols = size2;
        array_ = new T *[Rows];
        for (int i = 0; i < Rows; i++) {
            array_[i] = new T[Cols];
        }
    }

    Matrix(const Matrix &matrix)
            : Matrix(matrix.Rows, matrix.Cols) {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                array_[i][j] = matrix.array_[i][j];
            }
        }
    }

    Matrix(Matrix &&another) noexcept
            : Rows(std::exchange(another.Rows, 0ull)),
              Cols(std::exchange(another.Cols, 0ull)),
              array_(std::exchange(another.array_, nullptr)) {}

    Matrix &operator=(Matrix &&another) noexcept {
        if (&another == this)
            return *this;

        delete[] array_;
        Rows = std::exchange(another.Rows, 0ull);
        Cols = std::exchange(another.Cols, 0ull);
        array_ = std::exchange(another.pointer_, nullptr);
        return *this;
    }

    Matrix &operator=(const Matrix &another) {
        if (&another == this)
            return *this;
        Matrix copy(another);
        std::swap(Rows, copy.Rows);
        std::swap(Cols, copy.Cols);
        std::swap(array_, copy.array_);
        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < Rows; i++) {
            if (array_[i] != nullptr) {
                delete[] array_[i];
            }
        }
        delete[] array_;
    };


    void operator+(const Matrix &another) {
        if (another.Rows == Rows) {
            if (another.Cols == Cols) {
                for (int i = 0; i < Rows; i++) {
                    for (int j = 0; j < Cols; j++) {
                        array_[i][j] = array_[i][j] + another.array_[i][j];
                    }
                }
            } else {
                throw std::out_of_range("sizes are not equal");
            }
        } else {
            throw std::out_of_range("sizes are not equal");
        }
    }


    void operator+=(const int k) {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                array_[i][j] += k;
            }
        }
    }

    void operator-=(const int k) {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                array_[i][j] -= k;
            }
        }
    }

    void operator*=(const int k) {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                array_[i][j] *= k;
            }
        }
    }

    void operator/=(const int k) {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                array_[i][j] /= k;
            }
        }
    }

    void operator-(const Matrix &another) {
        if (another.Rows == Rows) {
            if (another.Cols == Cols) {
                for (int i = 0; i < Rows; i++) {
                    for (int j = 0; j < Cols; j++) {
                        array_[i][j] = array_[i][j] - another.array_[i][j];
                    }
                }
            } else {
                throw std::out_of_range("sizes are not equal");
            }
        } else {
            throw std::out_of_range("sizes are not equal");
        }
    }


    Matrix<T> operator*(const Matrix &another) {
        Matrix<T> m(Rows, another.Cols);
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < another.Cols; ++j) {
                m.array_[i][j] = 0;
                for (int k = 0; k < Cols; ++k)
                    m.array_[i][j] += array_[i][k] * another.array_[k][j];
            }
        }
        return m;
    }




    void fillingkeyboardMatrix() {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                std::cout << "Entering value";
                std::cin >> array_[i][j];
            }
        }
    }

    void fillingMatrix(int a, int b) {
        std::random_device rand;
        std::uniform_int_distribution<T> distribution(a, b);
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                array_[i][j] = distribution(rand);
            }
        }
    }

    T max() {
        T max = array_[0][0];
        for (int i = 1; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                if (max < array_[i][j]) {
                    max = array_[i][j];
                }
            }
        }
        return max;
    }


    T min() {
        T min = array_[0][0];
        for (int i = 1; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                if (min > array_[i][j]) {
                    min = array_[i][j];
                }
            }
        }
        return max;
    }

    const size_t &rows() const {
        return Rows;
    }

    const size_t &cols() const {
        return Cols;
    }

    size_t &rows() {
        return Rows;
    }

    size_t &cols() {
        return Cols;
    }

    const T get(size_t index1, size_t index2) const {
        return array_[index1][index2];
    }

    void print() {
        std::cout << std::endl;
        for (int i = 0; i < Rows; i++) {
            std::cout << "[";
            for (int j = 0; j < Cols; j++) {
                std::cout << array_[i][j] << " ";
                if (j == Cols - 1) {
                    std::cout << "]";
                } else {
                    std::cout << ",";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

private:
    size_t Rows;
    size_t Cols;
    T **array_;
};

#endif //MATRIX_H
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
  private:
    T* data;
    int capacity; // ? Ukuran maksimal array
    int size; // ? Banyaknya element pada array

    /**
     * * Fungsi untuk memanipulasi ukuran array selama program berjalan
     * ? Hanya baru bisa menambah ukuran
     * TODO Buat logic untuk mengurangi ukuran (penting untuk menjaga memori tidak penuh)
     */
    void resize() {
      // ? Kapasitas dikali 2 setiap kali perlu penambahan
      this->capacity *= 2;
      // ? Buat array baru dengan kapasitas baru
      T* new_array = new T[this->capacity];

      // ? Salin data dari array lama ke array baru
      for (int i = 0; i < this->size; i++) {
        new_array[i] = this->data[i];
      }

      // ? Hapus data array lama dan assign pointer untuk array baru
      delete[] this->data;
      this->data = new_array;
    }

  public:
    Array() {
      this->capacity = 2; // ? Inisiasi ukuran array
      this->size = 0;
      this->data = new T[this->capacity];
    }

    ~Array() {
      delete[] this->data;
    }

    /**
     * * Fungsi untuk MENAMBAH element array dari posisi belakang
     */
    void push_back(T value) {
      if (this->size == this->capacity) {
        this->resize();
      }
      this->data[this->size] = value;
      this->size += 1;
    }

    /**
     * * Fungsi untuk MENGHAPUS element array dari posisi belakang
     */
    void pop_back() {
      if (this->size > 0) {
        this->size -= 1;
      }
    }

    /**
     * * Fungsi untuk MENAMBAH element array dari posisi depan
     */
    void unshift(T value) {
      if (this->size == this->capacity) {
        this->resize();
      }

      for (int i = this->size; i > 0; i--) {
        this->data[i] = this->data[i - 1];
      }
      this->data[0] = value;

      this->size += 1;
    }

    /**
     * * Fungsi untuk MENGHAPUS element array dari posisi belakang
     */
    void shift() {
      if (this->size == 0) {
        throw std::domain_error("Array is empty");
      }

      for (int i = 0; i < this->size - 1; i++) {
        this->data[i] = this->data[i + 1];
      }
      
      this->size -= 1;
    }

    /**
     * * Mengakses element array
     */
    T get(int i) const {
      return this->data[i];
    }

    /**
     * * Mengembalikan pointer array
     */
    T* get_arr() const {
      return this->data;
    }

    /**
     * * Mengembalikan banyak element dari array
     */
    int get_size() const {
      return this->size;
    }

    /**
     * * Mengembalikan kapasitas array
     */
    int get_capacity() const {
      return this->capacity;
    }
};

#endif
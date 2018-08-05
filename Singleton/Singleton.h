//
// Created by cestl on 2018/5/9 0009.
//

#ifndef LEETCODE_SINGLETON_H
#define LEETCODE_SINGLETON_H

#include "../config.h"

template <typename T>
class Singleton {
 public:
  template <typename... Args>
  static T *Instance(Args &&... args) {
    if (m_pInstance == nullptr) {
      m_pInstance = new T(std::forward<Args>(args)...);
    }
    return m_pInstance;
  }

  static T *GetInstance() {
    if (m_pInstance == nullptr) {
      throw std::logic_error(
          "the instance is not init, please initialize the instance first!");
    }
    return m_pInstance;
  }

  static void DestroyInstance() {
    if (m_pInstance != nullptr) delete m_pInstance;
    m_pInstance = nullptr;
  }

 private:
  Singleton(void);

  virtual ~Singleton();

  Singleton(const Singleton &);

  Singleton &operator=(const Singleton &);

  static T *m_pInstance;
};

template <typename T>
T *Singleton<T>::m_pInstance = nullptr;

#endif  // LEETCODE_SINGLETON_H

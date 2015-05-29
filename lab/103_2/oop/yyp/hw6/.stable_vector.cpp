#include "stable_vector.hpp"
#include <iostream>
using namespace std;


template<typename T> 
stable_vector<T>::stable_vector(){
}

template<typename T>
stable_vector<T>::stable_vector(const size_type n, const T& value){
}

template<typename T>
template<typename InputIterator>
stable_vector<T>::stable_vector(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type*){
}

template<typename T>
stable_vector<T>::stable_vector(const stable_vector& rhs){
}

template<typename T>
stable_vector<T>& stable_vector<T>::operator=(const stable_vector& rhs){
}

template<typename T>
stable_vector<T>::~stable_vector(){
}

template<typename T>
void stable_vector<T>::assign(const size_type n, const T& value){
}

template<typename T>
template<typename InputIterator>
void stable_vector<T>::assign(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type*){
}

template<typename T>
typename stable_vector<T>::reference stable_vector<T>::operator[](const size_type pos){
}

template<typename T>
typename stable_vector<T>::const_reference stable_vector<T>::operator[](const size_type pos) const {
}

template<typename T>
typename stable_vector<T>::reference stable_vector<T>::front(){
}

template<typename T>
typename stable_vector<T>::const_reference stable_vector<T>::front() const {
}

template<typename T>
typename stable_vector<T>::reference stable_vector<T>::back(){
}

template<typename T>
typename stable_vector<T>::const_reference stable_vector<T>::back() const {
}

template<typename T>
typename stable_vector<T>::iterator stable_vector<T>::begin(){
}

template<typename T>
typename stable_vector<T>::const_iterator stable_vector<T>::begin() const {
}

template<typename T>
typename stable_vector<T>::const_iterator stable_vector<T>::cbegin() const {
}

template<typename T>
typename stable_vector<T>::iterator stable_vector<T>::end(){
}

template<typename T>
typename stable_vector<T>::const_iterator stable_vector<T>::end() const {
}

template<typename T>
typename stable_vector<T>::const_iterator stable_vector<T>::cend() const {
}

template<typename T>
bool stable_vector<T>::empty() const {
}	

template<typename T>
typename stable_vector<T>::size_type stable_vector<T>::size() const {
}

template<typename T>
void stable_vector<T>::clear(){
}

template<typename T>
typename stable_vector<T>::iterator stable_vector<T>::insert(typename stable_vector<T>::const_iterator pos, const T& value){
}

template<typename T>
template<typename InputIterator>
typename stable_vector<T>::iterator stable_vector<T>::insert(typename stable_vector<T>::const_iterator pos, InputIterator first, InputIterator last){
}

template<typename T>
typename stable_vector<T>::iterator stable_vector<T>::erase(typename stable_vector<T>::const_iterator pos){
}

template<typename T>
typename stable_vector<T>::iterator stable_vector<T>::erase(typename stable_vector<T>::const_iterator first, typename stable_vector<T>::const_iterator last){
}

template<typename T>
void stable_vector<T>::push_back(const T& value){
	insert(const_iterator(end()), value);
}

template<typename T>
void stable_vector<T>::pop_back(){
}

template<typename T>
void stable_vector<T>::resize(typename stable_vector<T>::size_type count, const T& value){
}

template<typename T>
void stable_vector<T>::swap(stable_vector<T>& other){
}

template<typename T>
bool operator==(const stable_vector<T>& lhs, const stable_vector<T>& rhs){
}
template<typename T>
bool operator!=(const stable_vector<T>& lhs, const stable_vector<T>& rhs){
}
template<typename T>
bool operator< (const stable_vector<T>& lhs, const stable_vector<T>& rhs){
}
template<typename T>
bool operator<=(const stable_vector<T>& lhs, const stable_vector<T>& rhs){
}
template<typename T>
bool operator> (const stable_vector<T>& lhs, const stable_vector<T>& rhs){
}
template<typename T>
bool operator>=(const stable_vector<T>& lhs, const stable_vector<T>& rhs){
}

/*==========iterator==========*/
template<typename T>
stable_vector<T>::iterator::iterator(stable_vector<T>::node* const n_){
}

template<typename T>
stable_vector<T>::iterator::iterator(const stable_vector<T>::iterator& rhs){
}

template<typename T>
typename stable_vector<T>::iterator& stable_vector<T>::iterator::operator=(const typename stable_vector<T>::iterator& rhs){
}

template<typename T>
stable_vector<T>::iterator::~iterator(){
}

template<typename T>
typename stable_vector<T>::iterator::reference stable_vector<T>::iterator::operator*() const {
}

template<typename T>
typename stable_vector<T>::iterator operator+(typename stable_vector<T>::iterator it, const typename stable_vector<T>::iterator::difference_type n){
}

template<typename T>
typename stable_vector<T>::iterator operator+(const typename stable_vector<T>::iterator::difference_type n, typename stable_vector<T>::iterator it){
}

template<typename T>
typename stable_vector<T>::iterator operator-(typename stable_vector<T>::iterator it, typename stable_vector<T>::iterator::difference_type n){

}

template<typename T>
typename stable_vector<T>::iterator::difference_type operator-(const typename stable_vector<T>::iterator lhs, const typename stable_vector<T>::iterator rhs){
}

template<typename T>
typename stable_vector<T>::iterator& stable_vector<T>::iterator::operator+=(const typename stable_vector<T>::iterator::difference_type n){
}

template<typename T>
typename stable_vector<T>::iterator& stable_vector<T>::iterator::operator-=(const typename stable_vector<T>::iterator::difference_type n){
}

template<typename T>
typename stable_vector<T>::iterator& stable_vector<T>::iterator::operator++(){
}

template<typename T>
typename stable_vector<T>::iterator stable_vector<T>::iterator::operator++(int){
}

template<typename T>
typename stable_vector<T>::iterator& stable_vector<T>::iterator::operator--(){
}

template<typename T>
typename stable_vector<T>::iterator stable_vector<T>::iterator::operator--(int){
}

template<typename T>
typename stable_vector<T>::iterator::reference stable_vector<T>::iterator::operator[](const typename stable_vector<T>::iterator::difference_type n){
}

template<typename T>
typename stable_vector<T>::const_reference stable_vector<T>::iterator::operator[](const typename stable_vector<T>::iterator::difference_type n) const {
}

template<typename T>
stable_vector<T>::iterator::operator const_iterator() const {
}

template<typename T>
bool operator==(const typename stable_vector<T>::iterator lhs, const typename stable_vector<T>::iterator rhs){
}

template<typename T>
bool operator!=(const typename stable_vector<T>::iterator lhs, const typename stable_vector<T>::iterator rhs){
}

template<typename T>
bool operator< (const typename stable_vector<T>::iterator lhs, const typename stable_vector<T>::iterator rhs){
}

template<typename T>
bool operator<=(const typename stable_vector<T>::iterator lhs, const typename stable_vector<T>::iterator rhs){
}

template<typename T>
bool operator> (const typename stable_vector<T>::iterator lhs, const typename stable_vector<T>::iterator rhs){
}

template<typename T>
bool operator>=(const typename stable_vector<T>::iterator lhs, const typename stable_vector<T>::iterator rhs){
}

/*==========const_iterator==========*/


template<typename T>
stable_vector<T>::const_iterator::const_iterator(const typename stable_vector<T>::node* const n_){
}

template<typename T>
stable_vector<T>::const_iterator::const_iterator(const typename stable_vector<T>::const_iterator& rhs){
}

template<typename T>
typename stable_vector<T>::const_iterator& stable_vector<T>::const_iterator::operator=(const typename stable_vector<T>::const_iterator& rhs){
}

template<typename T>
stable_vector<T>::const_iterator::~const_iterator(){
}

template<typename T>
typename stable_vector<T>::const_iterator operator+(typename stable_vector<T>::const_iterator it, const typename stable_vector<T>::const_iterator::difference_type n){
}

template<typename T>
typename stable_vector<T>::const_iterator operator+(const typename stable_vector<T>::const_iterator::difference_type n, typename stable_vector<T>::const_iterator it){
}

template<typename T>
typename stable_vector<T>::const_iterator operator-(typename stable_vector<T>::const_iterator it, const typename stable_vector<T>::const_iterator::difference_type n){
}

template<typename T>
typename stable_vector<T>::const_iterator::differenct_type operator-(const typename stable_vector<T>::const_iterator n, const typename stable_vector<T>::const_iterator it){
}


template<typename T>
typename stable_vector<T>::const_iterator& stable_vector<T>::const_iterator::operator+=(const typename stable_vector<T>::const_iterator::difference_type n){
}

template<typename T>
typename stable_vector<T>::const_iterator& stable_vector<T>::const_iterator::operator-=(const typename stable_vector<T>::const_iterator::difference_type n){
}

template<typename T>
typename stable_vector<T>::const_reference stable_vector<T>::const_iterator::operator*() const {
}

template<typename T>
typename stable_vector<T>::const_iterator& stable_vector<T>::const_iterator::operator++(){
}

template<typename T>
typename stable_vector<T>::const_iterator stable_vector<T>::const_iterator::operator++(int){
}

template<typename T>
typename stable_vector<T>::const_iterator& stable_vector<T>::const_iterator::operator--(){
}

template<typename T>
typename stable_vector<T>::const_iterator stable_vector<T>::const_iterator::operator--(int){
}

template<typename T>
typename stable_vector<T>::const_reference stable_vector<T>::const_iterator::operator[](const typename stable_vector<T>::const_iterator::difference_type n) const {
}

template<typename T>
bool operator==(const typename stable_vector<T>::const_iterator lhs, const typename stable_vector<T>::const_iterator rhs){
}

template<typename T>
bool operator!=(const typename stable_vector<T>::const_iterator lhs, const typename stable_vector<T>::const_iterator rhs){
}

template<typename T>
bool operator< (const typename stable_vector<T>::const_iterator lhs, const typename stable_vector<T>::const_iterator rhs){
}

template<typename T>
bool operator<=(const typename stable_vector<T>::const_iterator lhs, const typename stable_vector<T>::const_iterator rhs){
}

template<typename T>
bool operator> (const typename stable_vector<T>::const_iterator lhs, const typename stable_vector<T>::const_iterator rhs){
}

template<typename T>
bool operator>=(const typename stable_vector<T>::const_iterator lhs, const typename stable_vector<T>::const_iterator rhs){
}
int main(){
}

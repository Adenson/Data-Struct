#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Insert_Sort(int* arr, int n);//��������
void Shellsert_Sort(int* arr, int n);//ϣ������
void Slect_Sort(int* arr, int n);//ѡ������
void Heap_Sort(int* arr, int n);//������
void Bubble_Sort(int* arr, int left);//ð������

void quick_Sort1(int* arr, int left, int right);//��������
void quick_Sort2(int* arr, int left, int right);//��������

void Merge_Sort(int* arr, int left, int right);//�鲢����
void Merge_Sort2(int* arr, int left, int right);//�鲢����

void CountSort(int* arr, int left, int right);//��������

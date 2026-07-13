# Median Filter Based Noise Reduction
Implementation of Median Filtering for Image Noise Reduction using C

구체적인 알고리즘 동작 과정과 실행 결과는 report.pdf에 첨부하였습니다.

Median Filter를 이용하여 노이즈가 포함된 2차원 데이터를 복원하는 프로그램을 C 언어로 구현한 프로젝트입니다. 입력 데이터를 텍스트 파일에서 읽어온 후 각 위치의 주변 3×3 영역을 분석하여 중앙값(Median)으로 대체함으로써 Salt-and-Pepper Noise를 효과적으로 제거하는 것을 목표로 하였습니다.

Filtering 과정에서는 Heap Sort를 이용하여 주변 픽셀을 정렬한 뒤 중앙값을 선택하며, 필터링된 결과를 새로운 텍스트 파일로 저장하도록 구현하였습니다.

# 🚀 프로젝트 개요
본 프로젝트는 Median Filter 알고리즘을 이용하여 노이즈가 포함된 데이터를 복원하는 프로그램입니다. 입력 데이터(noisy_data.txt)를 읽어온 뒤 각 위치를 기준으로 3×3 Window의 주변 값을 수집하고, 정렬을 통해 중앙값(Median)을 계산하여 새로운 데이터로 대체합니다.

가장자리 영역은 이미지 범위를 벗어난 데이터를 제외하도록 처리하였으며, 모든 위치에 대해 동일한 과정을 반복하여 노이즈가 제거된 결과를 생성합니다. 최종 결과는 filtered_result.txt 파일로 저장되어 원본 데이터와 필터링 결과를 비교할 수 있도록 구현하였습니다.
<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/437e32f7-90af-4ef8-b271-cd22e224d437" />
<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/cdf6bc62-4bb4-4575-b548-e669bb9eb7d1" />

# 특징
Median Filtering : 3×3 Window 기반 중앙값 필터를 이용한 노이즈 제거

Heap Sort 적용 : 주변 픽셀을 Heap Sort로 정렬하여 Median 값 계산

Boundary Handling : 이미지 경계를 벗어나는 픽셀은 제외하여 안정적인 필터링 수행

Dynamic Memory Allocation : malloc과 calloc을 이용한 메모리 관리

File I/O : 입력(noisy_data.txt)과 출력(filtered_result.txt)을 파일 형태로 처리

Modular Design : read_file(), median_filtering(), heap_sort(), downheap() 등 기능별 함수로 모듈화하여 구현

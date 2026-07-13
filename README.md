# Median Filter Based Noise Reduction
Median filter implementation for image noise reduction and enhancement.

# 🚀 프로젝트 개요
15×15 Binary Map에서 연결된 객체를 탐색하고 각각의 객체에 고유한 Label을 부여하는 Connected Component Labeling 알고리즘을 C 언어로 구현한 프로젝트입니다. Stack을 이용한 방식으로 8방향 연결성을 탐색하며, 재귀 호출 대신 직접 구현한 Stack 자료구조를 사용하여 메모리 사용을 효율적으로 관리하였습니다.

입력 맵을 왼쪽에서 오른쪽, 위에서 아래 순서로 탐색하면서 값이 1인 지점을 발견하면 새로운 객체 탐색을 시작합니다. 탐색 과정에서는 현재 좌표와 이동 방향을 Stack에 저장하고, 주변의 연결된 픽셀을 모두 방문하며 동일한 Label을 부여합니다. 더 이상 연결된 픽셀이 존재하지 않으면 Stack에서 이전 위치를 꺼내 Backtracking을 수행하여 남은 경로를 계속 탐색합니다.

최종적으로 모든 연결 요소를 탐색한 후 각 객체를 서로 다른 번호로 Labeling하여 출력하며, Stack 자료구조와 DFS 알고리즘을 활용한 Connected Component Labeling의 동작 원리를 학습하는 것을 목표로 하였습니다.

#include <iostream>

using namespace std;

void func(int cnt, int n) {

	if (cnt == n) {
		for (int i = 0; i < cnt * 4; i++) {
			cout << '_';
		}
		cout << "\"����Լ��� ������?\"\n";
		for (int i = 0; i < cnt * 4; i++) {
			cout << '_';
		}
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i = 0; i < cnt * 4; i++) {
			cout << '_';
		}
		cout << "��� �亯�Ͽ���.\n";
		return;
	}
	for (int i = 0; i < cnt * 4; i++) {
		cout << '_';
	}
	cout << "\"����Լ��� ������?\"\n";
	for (int i = 0; i < cnt * 4; i++) {
		cout << '_';
	}
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	for (int i = 0; i < cnt * 4; i++) {
		cout << '_';
	}
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	for (int i = 0; i < cnt * 4; i++) {
		cout << '_';
	}
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	func(cnt + 1, n);
	for (int i = 0; i < cnt * 4; i++) {
		cout << '_';
	}
	cout << "��� �亯�Ͽ���.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	func(0, n);

	return 0;
}
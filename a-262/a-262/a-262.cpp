#define x first
#define y second
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using point = pair<long long, long long>;

using namespace std;

int ccw(point a, point b, point c) {
	ll res = a.x * b.y + b.x * c.y + c.x * a.y;
	res -= a.y * b.x + b.y * c.x + c.y * a.x;
	return (res > 0) - (res < 0);
}

ll dist(point a, point b) {
	if (a > b) {
		swap(a, b);
	}
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

vector<point> convexhull(vector<point> &vc) {
	sort(vc.begin(), vc.end());
	if (vc.size() <= 3) {
		return vc;
	}
	vector<point> up, down;
	for (auto &i : vc) {
		while (up.size() >= 2 && ccw(up[up.size() - 2], up.back(), i) >= 0) {
			up.pop_back();
		}
		up.push_back(i);
		while (down.size() >= 2 && ccw(down[down.size()-2],down.back(), i) <= 0) {
			down.pop_back();
		}
		down.push_back(i);
	}
	ll maxDist = -0;
	ll upX;
	ll upY;
	ll downX;
	ll downY;
	for (int i = 0, j = down.size() - 1; i + 1 < up.size() || j > 0;) {
		maxDist = max(maxDist, dist(up[i],down[j]));
		upX = up[i + 1].x - up[i].x;
		upY = up[i + 1].y - up[i].y;
		downX = down[j].x - down[j - 1].x;
		downY = down[j].y - down[j - 1].y;
		if (i + 1 == up.size()) {
			j--;
		}
		else if (j == 0) {
			i++;
		}
		else if (upY * downX > downY * upX) {
			i++;
		}
		else {
			j--;
		}
	}
	vector<point> ans;
	ans.push_back({ upX,upY });
	ans.push_back({downX,downY});
	return ans;
}

vector<point> convexhull2(vector<point>& vc) {
	swap(vc[0], *min_element(vc.begin(),vc.end()));
	sort(vc.begin() + 1, vc.end(), [&](auto a, auto b) {
		int c = ccw(vc[0], a, b);
		if (c != 0) {
			return c > 0;
		}
		return dist(vc[0], a) < dist(vc[0], b);
	});
	vector<point> ans;
	for (auto i : vc) {
		while (ans.size() >= 2 && ccw(ans[ans.size() - 2], ans.back(), i) <= 0) {
			ans.pop_back();
		}
		ans.push_back(i);
	}
	return ans;
}

int main()
{

}
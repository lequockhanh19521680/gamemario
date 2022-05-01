
#define ADJUST_X_SCORE 62
#define ADJUST_Y_SCORE 5
class CHUD
{
	float x, y;
	ULONGLONG now_time;
	int time;
	CFont font;
	CPower* power;
public:
	CHUD(float x, float y);
	void Render(CMario* mario, int remainingTime);
	string FillNumber(string s, UINT fillNumber);
	void GetBoundingBox(float& l, float& t, float& r, float& b) {}
	~CHUD() {}
};



int growingPlant(int u, int d, int ds)
{
  int cnt=0;
  int h=0;
    while(true){
      h+=u;
      ++cnt;
      if(h>=ds) break;
      h-=d;
    }
  return cnt;
}

///////////////////////
int growingPlant(int upSpeed, int downSpeed, int desiredHeight)
{
    int h = upSpeed;
    int day = 1;
    while(h < desiredHeight){
      h += (upSpeed - downSpeed);
      day++;
    }
    return day;
}

/////////////////
constexpr int growingPlant(
  const int upSpeed, 
  const int downSpeed, 
  const int desiredHeight
) noexcept {
  return upSpeed >= desiredHeight ? 1 : 
                      1 + (desiredHeight - downSpeed - 1) / (upSpeed - downSpeed);
}

///////////////////////
int growingPlant(const int up, const int down, const int desire)
{
    const int t = up - down;
    return std::max((desire - up + t - 1) / t,0) + 1;
}

///////////////////
#define growingPlant(upSpeed, downSpeed, desiredHeight) ((desiredHeight -= upSpeed) < 0 ? 1 : desiredHeight / (upSpeed - downSpeed) + 1 + (desiredHeight % (upSpeed - downSpeed) > 0))
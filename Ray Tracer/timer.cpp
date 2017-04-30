//Declaration header
#include"timer.h"


//Exposing namespace
using namespace std::chrono;


	//Private functions


	double timer::in_seconds(mClock::duration pDuration) const
	{
		return (duration_cast<microseconds>(pDuration).count() / 1000000.0);
	}


	//Public functions
	


	timer::timer()
	{
		init();
	}


	void timer::init()
	{
		mLast = mClock::now();
		mLastTime = mClock::now();

		mCounter = 0;
		mFPS = 0;
	}


	void timer::update()
	{

		//Updating mElapsedTime
		mCurrent = mClock::now();
		mElapsedTime = in_seconds(mCurrent-mLast);
		mLast = mCurrent;

		//Updating fps

		mCounter++;
		if (in_seconds(mCurrent - mLastTime) > 1.0f)
		{
			mFPS = mCounter;
			mCounter = 0;
			mLastTime = mCurrent;
		}

	}

	std::string timer::get_current_time_and_date()
		{
			auto now = std::chrono::system_clock::now();
			auto in_time_t = std::chrono::system_clock::to_time_t(now);

			std::stringstream ss;
			ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
			return ss.str();
		

	}


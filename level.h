class Level
{
    public:
        Level();
        void next();
        int getLevelNumber();
        int getTickTime();
        int getPointMultiplier();
   private:
        int levelNumber;
        int tickTime;
        int pointMultiplier;
};
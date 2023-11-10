class BrowserHistory
{
private:
    string currentPage;
    vector<string> history;
    int curIndex = 0, totalSize = 0;

public:

    BrowserHistory(string homepage)
    {
        currentPage = homepage;
        history.push_back(currentPage);
        totalSize = history.size();
    }

    void visit(string url)
    {
        curIndex++;
        currentPage = url;
        if(curIndex == history.size()){
            history.push_back(url);
            totalSize = history.size();
        }
        else{
            totalSize = curIndex + 1;
            history.erase(history.begin() + curIndex, history.end());
            history.push_back(url);
        }
    }

    string back(int steps)
    {
        if (curIndex - steps < 0)
        {
            curIndex = 0;
            currentPage = history[curIndex];
            return currentPage;
        }
        else
        {
            curIndex -= steps;
            currentPage = history[curIndex];
            return currentPage;
        }
    }

    string forward(int steps)
    {
        if (curIndex + steps > history.size() - 1)
        {
            curIndex = history.size() - 1;
            currentPage = history[curIndex];
            return currentPage;
        }
        else
        {
            curIndex += steps;
            currentPage = history[curIndex];
            return currentPage;
        }
    }
};
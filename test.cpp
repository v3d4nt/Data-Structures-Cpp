bool operator<(Box &B)
{
    if (length < B.length)
    {
        return true;
    }
    else if (length == B.length)
    {
        if (breadth < B.breadth)
        {
            return true;
        }
        else if (breadth == B.breadth)
        {
            if (height < B.height)
            {
                return true;
            }
        }
    }

    return false;
}
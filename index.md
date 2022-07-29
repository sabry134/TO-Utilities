## Tanki Fund Tracker

A convenient tool made with Python using the Plotly and Streamlit libraries to track Tanki Funds over time.

Provides the following analytics:
- At-a-glance stats: Current Fund, Recent Fund Growth, Final Fund Estimates.
- Checkpoint Information: Next Checkpoint, Final Checkpoint, Time to Next Checkpoint.
- Daily Fund changes in a table.
- Hourly and overall plots for the Tanki Fund.

### More Information

Fund estimates are made with multiple linear regression on the elapsed time. Features were chosen as follows:
- `Fund["Days"]`: primary source of information. When used alone, it creates a linear prediction.
- `Fund["Days (Log)"]`: used to account for the fast growth towards the beginning of the fund. A logarithmic graph grows quickly at first, then slows down, similar to the Tanki Fund - initial hype makes the fund grow quickly, but then the fund evens out over time.
- `Fund["Days^2"]`: used to account for the fast fund growth rate towards the end. This is similar to the logarithmic feature, but the rate of growth is slower.

Checkpoint Estimates are made with (modified) Newton's method. We have a smooth prediction graph that is mostly accurate from the linear model above; now let's put it to use here.

Newton's method works basically like this:
```python
def newton(f, df, p0, tol):
    # estimates the zero of the function using Newton's method within tol
    while True:
        p = p0 - f(p0) / df(p0) # fixed point iteration
        if abs(p - p0) <= tol:
            break
        p = p0
    return p
```
Since the regression model isn't easily differentiable, I used a modified method that generates similar results without `df`, the derivative of the function. Putting it all together, running (modified) Newton's method with a shift to account for the next checkpoint gives us an accurate prediction of the time to reach the next checkpoint.

Interested in learning more and checking out the fund tracker for yourself? You can find the fund tracker [here](https://fund-vis-v2.herokuapp.com).

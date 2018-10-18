main :: IO()
main = do
    b <- readLn
    t <- readLn
    n <- readLn
    putStrLn $ if 2*b+3*t <= n then "LOOT!" else "RHUM!"

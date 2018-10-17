main :: IO()
main = do
    line <- getLine
    let li = map (read :: String -> Int) $ words line
    print ( ans (li!!0) (li!!1) (li!!2) )

ans :: Int -> Int -> Int -> Int
ans p l g = do
        length [(x,y)| x<-[0..m], y<-[0..l], x*x+y+x*y==g]
            where m = min p $ floor $ sqrt $ fromIntegral g -- x really cannot be bigger than sqrt(g)

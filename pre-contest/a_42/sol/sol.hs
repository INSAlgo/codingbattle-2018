main = do
    n <- readLn
    putStrLn $ ans n ++ "\n"

ans :: Int -> String
ans n | n<42 = "More"
      | n==42 = "Bingo!"
      | otherwise = "Less"

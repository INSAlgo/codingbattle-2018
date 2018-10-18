import Data.List

main :: IO()
main = do
    s <- getLine
    n_tmp <- getLine
    let n = read n_tmp :: Int
    putStrLn $ smart_iterate f s !! n

-- f takes a string representing a number and returns the result of one iteration on that string
-- It sorts all the numbers first ("1211" -> "1112") , then groups them ("1112" -> ["111", "2"]).
-- It then replaces each string by its length followed by its first element (["111", "2"] -> ["31", "12"]).
-- It finally concatenates all elements in the list (["31", "12"] -> "3112")²
f :: String -> String
f n = concat $ map (\s -> (show.length) s ++ [s!!0]) $ group $ sort n

-- smart_iterate is a function that takes a function f, a starting element n and returns an infinite
-- list made up of successive applications of f, starting with n. Its difference with the function
-- iterate in Data.List is that it checks for cycles of length up to 3, in order to optimise performance.
smart_iterate :: (Eq a) => (a->a) -> a -> [a]
smart_iterate f n = sih f n [n]

-- sih is a helper function for smart_iterate which passes the current list as an argument to
-- check for cycles.
sih :: (Eq a) => (a->a) -> a -> [a] -> [a]
sih f n l | prev == f prev = l ++ repeat prev
          | length l > 1 && pprev == f prev = l ++ cycle [pprev, prev]
          | length l > 2 && ppprev == f prev = l ++ cycle [ppprev, pprev, prev]
          | otherwise = sih f n (l ++ [f prev])
            where
                prev = l!!(length l - 1)
                pprev = l!!(length l - 2)
                ppprev = l!!(length l - 3)

import Control.Monad
import Data.Char
--main = do
--    contents <- getContents
--    putStrLn "You added " ++ (show (numlines contents)) ++ " lines" where
--        numlines x = length (lines x)
--        
--        

data RunLength = Characters Int | Spaces Int | EOL
lineToUncompressedRunLength :: [Char] -> [RunLength]
lineToUncompressedRunLength = map (\c -> if c == ' ' then Spaces 1 else Characters 1)

lineToRunLength :: [Char] -> [RunLength]
lineToRunLength x = foldr compressor [EOL] (lineToUncompressedRunLength x) where
    compressor :: RunLength -> [RunLength] -> [RunLength]
    compressor (Characters x) (Characters y:ys) = (Characters (x+y)):ys
    compressor (Spaces x) (Spaces y:ys) = (Spaces (x+y)):ys
    compressor x y = x:y

runLengthToInts :: [RunLength] -> [Int]
runLengthToInts = map f where
    f :: RunLength -> Int
    f (Characters n) = n
    f (Spaces n) = n
    f (EOL) = -1

intsToCCode :: [Int] -> [Char]
intsToCCode x = "{" ++ (innerArray x) ++ "};" where
    innerArray :: [Int] -> [Char]
    innerArray [] = []
    innerArray (x:[]) = (show x)
    innerArray (-1:xs) = (show (-1)) ++ ",\n" ++ (innerArray xs)
    innerArray (x:xs) = (show x) ++ ", " ++ (innerArray xs)

linesToCode :: [[Char]] -> [Char]
linesToCode lines = intsToCCode (runLengthToInts allRunLengths) where
    allRunLengths = foldl (++) [] (map lineToRunLength lines)

main = do
    contents <- getContents
    putStrLn (linesToCode (lines contents))

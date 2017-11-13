-- reverse.hs (written by mrmaximuzz)
-- Reverses all the lines from stdin and prints the result
-- to stdout.

main :: IO ()
main = interact $ unlines . map reverse . lines

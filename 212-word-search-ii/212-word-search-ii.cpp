class Solution
{
	public:

		bool searchRecursively(const std::string &word, std::vector<std::vector<char>> &board, std::size_t charIndF, std::size_t iF,
				std::size_t jF, std::size_t charIndB, std::size_t iB, std::size_t jB, bool isForward)
		{
			if (word.size() == charIndF + 1 && charIndB < 1)
			{
				return true;
			}

			char temp;
			if (isForward)
			{
				temp = board[iB][jB];
				board[iB][jB] = 0;
				if (word.size() == charIndF + 1)
				{
					auto ret = searchRecursively(word, board, charIndF, iF, jF, charIndB, iB, jB, false);
					board[iB][jB] = temp;
					return ret;
				}

				if (board.size() > iF + 1 && board[iF + 1][jF] != 0 && board[iF + 1][jF] == word[charIndF + 1])
				{
					if (searchRecursively(word, board, charIndF + 1, iF + 1, jF, charIndB, iB, jB, false))
					{
						board[iB][jB] = temp;
						return true;
					}
				}
				if (0 < iF && board[iF - 1][jF] != 0 && board[iF - 1][jF] == word[charIndF + 1])
				{
					if (searchRecursively(word, board, charIndF + 1, iF - 1, jF, charIndB, iB, jB, false))
					{
						board[iB][jB] = temp;
						return true;
					}
				}
				if (board[iF].size() > jF + 1 && board[iF][jF + 1] != 0 && board[iF][jF + 1] == word[charIndF + 1])
				{
					if (searchRecursively(word, board, charIndF + 1, iF, jF + 1, charIndB, iB, jB, false))
					{
						board[iB][jB] = temp;
						return true;
					}
				}
				if (0 < jF && board[iF][jF - 1] != 0 && board[iF][jF - 1] == word[charIndF + 1])
				{
					if (searchRecursively(word, board, charIndF + 1, iF, jF - 1, charIndB, iB, jB, false))
					{
						board[iB][jB] = temp;
						return true;
					}
				}
				board[iB][jB] = temp;
			}
			else
			{
				temp = board[iF][jF];
				board[iF][jF] = 0;
				if (charIndB < 1)
				{
					auto ret = searchRecursively(word, board, charIndF, iF, jF, charIndB, iB, jB, true);
					board[iF][jF] = temp;
					return ret;
				}

				if (board.size() > iB + 1 && board[iB + 1][jB] != 0 && board[iB + 1][jB] == word[charIndB - 1])
				{
					if (searchRecursively(word, board, charIndF, iF, jF, charIndB - 1, iB + 1, jB, true))
					{
						board[iF][jF] = temp;
						return true;
					}
				}
				if (0 < iB && board[iB - 1][jB] != 0 && board[iB - 1][jB] == word[charIndB - 1])
				{
					if (searchRecursively(word, board, charIndF, iF, jF, charIndB - 1, iB - 1, jB, true))
					{
						board[iF][jF] = temp;
						return true;
					}
				}
				if (board[iB].size() > jB + 1 && board[iB][jB + 1] != 0 && board[iB][jB + 1] == word[charIndB - 1])
				{
					if (searchRecursively(word, board, charIndF, iF, jF, charIndB - 1, iB, jB + 1, true))
					{
						board[iF][jF] = temp;
						return true;
					}
				}
				if (0 < jB && board[iB][jB - 1] != 0 && board[iB][jB - 1] == word[charIndB - 1])
				{
					if (searchRecursively(word, board, charIndF, iF, jF, charIndB - 1, iB, jB - 1, true))
					{
						board[iF][jF] = temp;
						return true;
					}
				}
				board[iF][jF] = temp;
			}
			return false;
		}

		std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
		{
			std::unordered_multimap<char, std::pair<std::size_t, std::size_t>> map { };

			{
				std::size_t i { 0 };
				for (auto &b1 : board)
				{
					std::size_t j { 0 };
					for (auto &b2 : b1)
					{
						map.emplace(b2, std::make_pair(i, j));
						++j;
					}
					++i;
				}
			}

			std::vector<std::string> ret { };
			for (auto &w : words)
			{
				std::size_t minInd { 0 };

				{
					std::size_t i { 0 };
					auto m = map.equal_range(w[i]);
					auto dist = std::distance(m.first, m.second);
					for (auto &ch : w)
					{
						m = map.equal_range(ch);
						auto d = std::distance(m.first, m.second);
						if (d == 0)
						{
							goto GOTONEXSTONE;
						}
						if (dist > d)
						{
							dist = d;
							minInd = i;
						}
						++i;
					}
				}

				{
					auto m = map.equal_range(w[minInd]);
					while (m.first != m.second)
					{
						std::size_t i { m.first->second.first };
						std::size_t j { m.first->second.second };

						if (searchRecursively(w, board, minInd, i, j, minInd, i, j, true))
						{
							ret.emplace_back(std::move(w));
							break;
						}
						m.first++;
					}
				}
				GOTONEXSTONE: ;
			}

			return ret;
		}
};
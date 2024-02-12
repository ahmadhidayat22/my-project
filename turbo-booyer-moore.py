# def build_bad_char_table(pattern):
#     bad_char_table = {}
#     pattern_length = len(pattern)

#     for i in range(pattern_length - 1):
#         bad_char_table[pattern[i]] = pattern_length - i - 1

#     return bad_char_table

# def build_good_suffix_table(pattern):
#     pattern_length = len(pattern)
#     suffix_table = [0] * pattern_length
#     last_prefix_position = pattern_length

#     for i in range(pattern_length - 1, -1, -1):
#         if is_suffix(pattern, i + 1):
#             last_prefix_position = i + 1
#         suffix_table[pattern_length - i - 1] = last_prefix_position - i + pattern_length - 1

#     for i in range(pattern_length - 1):
#         k = pattern_length - i - 1
#         if k == suffix_table[k]:
#             last_prefix_position = pattern_length - k
#         suffix_table[k] = last_prefix_position

#     return suffix_table

# def is_suffix(pattern, p):
#     pattern_length = len(pattern)
#     j = 0

#     for i in range(p, pattern_length):
#         if pattern[i] != pattern[j]:
#             return False
#         j += 1

#     return True

# def turbo_search_pattern(text, pattern):
#     text_length = len(text)
#     pattern_length = len(pattern)
#     bad_char_table = build_bad_char_table(pattern)
#     good_suffix_table = build_good_suffix_table(pattern)
#     shift = 0

#     while shift <= text_length - pattern_length:
#         j = pattern_length - 1

#         while j >= 0 and pattern[j] == text[shift + j]:
#             j -= 1

#         if j < 0:
#             # Pattern ditemukan
#             print(f"Pattern '{pattern}' ditemukan pada indeks {shift}")
#             shift += good_suffix_table[0]
#         else:
#             bad_char_shift = bad_char_table.get(text[shift + j], -1)
#             good_suffix_shift = good_suffix_table[j]

#             shift += max(bad_char_shift, good_suffix_shift)
#             print("noo")


# text = "ini adalah contoh teks yang digunakan untuk mencari contoh"
# pattern = "contoh"

# turbo_search_pattern(text, pattern)

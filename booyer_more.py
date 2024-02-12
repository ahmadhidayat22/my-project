# def build_bad_char_table(pattern):
#     bad_char_table = {}
#     pattern_length = len(pattern)

#     for i in range(pattern_length - 1):
#         bad_char_table[pattern[i]] = pattern_length - i - 1

#     return bad_char_table

# def search_pattern(text, pattern):
#     text_length = len(text)
#     pattern_length = len(pattern)
#     bad_char_table = build_bad_char_table(pattern)
#     shift = 0

#     while shift <= text_length - pattern_length:
#         j = pattern_length - 1

#         while j >= 0 and pattern[j] == text[shift + j]:
#             j -= 1

#         if j < 0:
#             # Pattern ditemukan
#             print(f"Pattern ditemukan pada indeks {shift}")
#             shift += pattern_length
#         else:
#             bad_char_shift = bad_char_table.get(text[shift + j], -1)

#             good_suffix_shift = 1

#             if j < pattern_length - 1:
#                 good_suffix_shift = pattern_length - j - 1

#             shift += max(bad_char_shift, good_suffix_shift)


# text = "ini adalah contoh teks yang digunakan untuk mencari contoh"
# pattern = "teks"

# search_pattern(text, pattern)

#==================Penandaan Hasil Pencarian: Algoritma Boyer-Moore dapat digunakan untuk menandai lokasi di mana kata kunci atau frasa muncul dalam teks dokumen. Ini memungkinkan mesin pencari untuk menyoroti kata kunci dalam hasil pencarian yang diberikan kepada pengguna============

def highlight_keyword(text, keyword):
    keyword_length = len(keyword)
    highlighted_text = text
    # print(len(highlighted_text))
    start = 0
    while start < len(highlighted_text):
        index = highlighted_text.find(keyword, start)
        print(index)
        if index == -1:
            break
        end = index + keyword_length
        highlighted_text = highlighted_text[:index] + f"[{keyword}]" + highlighted_text[end:]
        print(highlighted_text)
        start = index + keyword_length + 4
        print(start)
    return highlighted_text

document = "di tengah hutan yang lebat, burung-burung bernyanyi dengan riang, sementara sinar matahari meresap melalui pepohonan yang tinggi. Suara aliran sungai mengalir pelan di kejauhan, menciptakan suasana yang tenang dan damai. di sini, alam menghadirkan keindahan yang luar biasa, dan semua makhluk hidup hidup dalam harmoni."

keyword = "di"
highlighted_document = highlight_keyword(document, keyword)
print()
print(highlighted_document)

#================================================================#

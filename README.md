# BÀI TẬP LỚN LẬP TRÌNH NÂNG CAO (INT2215)
# ---------------------------------------
# Đề tài: Hangman Olympia
# Người thực hiện: Lê Xuân Dương - K65CB, Khoa CNTT, Đại học Công nghệ - Đại học Quốc gia Hà Nội


# I: Ý tưởng:
- Xuất phát từ một trong những kí ức tuổi thơ: Đọc số từ 1 đến 80 bằng Tiếng Anh khi mới 3 tuổi.
- Xuất phát từ niềm đam mê mãnh liệt với "Đường lên đỉnh Olympia" - Gameshow kiến thức lâu đời bậc nhất tại Việt Nam.
- Củng cố từ kiến thức của game Hangman đã được học ở trên giảng đường.
-----> Game Hangman Olympia đã được lên ý tưởng từ những yếu tố ấy!

# II: Khái quát về Hangman Olympia:
- Được viết trên Code::Blocks 20.03, hoàn toàn bằng ngôn ngữ C++, không sử dụng SDL mà sử dụng giao diện Text.
- Cách chơi như Hangman truyền thống, nhưng không có hình vẽ người treo cổ, cũng không bị dừng lại sau khi sai 7 lần, không có cơ chế cho chơi nhiều lần.
- ĐẶC BIỆT: Có cơ chế bấm chuông trả lời từ cần đoán ngay khi tất cả các kí tự chưa được lật mở hết như phần "Vượt chướng ngại vật" của Olympia.

# III: Giao diện và Luật chơi:
- Khi bạn bắt đầu chạy chương trình, cửa sổ sẽ hiện ra như sau:
![image](https://user-images.githubusercontent.com/81974069/117321759-9f4ffe00-aeb7-11eb-8c1e-ca7858905ed9.png)
--------> Bạn được quyền chọn 1 trong 3 chế độ: Chế độ Người đố (Player 1) vs Người đoán (Player 2) (Để chọn chế độ này, bấm phím 1 rồi bấm Enter.); Chế độ Người (Player) vs Máy (Computer) (Để chọn chế độ này, bấm phím 2 rồi bấm Enter.); Chế độ Thoát game (Để chọn chế độ này, gõ từ "quit" rồi bấm Enter.).
- CHÚ Ý: Nếu gõ bất kì cái gì khác 1, 2 hay "quit" rồi bấm Enter, màn hình sẽ hiện ra như sau:
  ![image](https://user-images.githubusercontent.com/81974069/117322397-2dc47f80-aeb8-11eb-86b6-971bc8dfdeae.png)
- Nếu chọn Chế độ Người đố (Player 1) vs Người đoán (Player 2): Màn hình sẽ hiện ra như sau:
![image](https://user-images.githubusercontent.com/81974069/117323183-de328380-aeb8-11eb-81e0-395126c2bdd0.png)
        Khi đó, Người đố sẽ gõ một từ bất kì (không phụ thuộc vào file từ có sẵn) để Người đoán sẽ đoán từ. Khi đó, Người đoán được phép đoán từ với số lần được tính bằng công thức: SỐ LẦN = SỐ CHỮ CÁI TRONG TỪ + 3.
![image](https://user-images.githubusercontent.com/81974069/117324102-b09a0a00-aeb9-11eb-990a-7d1b25fd5fcb.png)
        Từ đấy, cách chơi giống với Hangman truyền thống, không có cơ chế tính điểm và đoán ngay. Người đố thắng khi Người đoán không đoán được từ trong số lần đoán chữ đã quy định, Người đoán thắng khi tất cả các chữ cái trong từ đã hiện ra khi chưa hết số lần đoán chữ.
- Nếu chọn Chế độ Người (Player) vs Máy (Computer): Màn hình sẽ hiện ra như sau:
![image](https://user-images.githubusercontent.com/81974069/117324903-711fed80-aeba-11eb-9289-867650587cf8.png)
        Khi đó, Máy sẽ tự động lựa chọn một từ trong file từ đã có sẵn. Người sẽ đoán từ như công thức đề cập ở trên.
 - Cách tính điểm: Một chữ cái đoán đúng tương ứng 10 điểm, một chữ cái đoán sai thì bị trừ 5 điểm, và chữ cái đoán sai sẽ hiển thị trên màn hình. Trong khi đoán chữ, có quyền bấm phím 1 rồi nhấn Enter để trả lời luôn từ cần đoán. Đoán từ chính xác, game kết thúc và Người được cộng thêm 40 điểm. Nếu đoán sai, Người phải quay lại đoán tiếp các chữ cái và vẫn có thể bấm 1-> ENTER bất cứ lúc nào.
![image](https://user-images.githubusercontent.com/81974069/117327190-8b5acb00-aebc-11eb-9178-e3d25049f720.png)
![image](https://user-images.githubusercontent.com/81974069/117327214-91e94280-aebc-11eb-9e3c-a79f9b90258b.png)
![image](https://user-images.githubusercontent.com/81974069/117327402-c1984a80-aebc-11eb-86ff-1ede02e5006c.png)
 - Nếu các chữ cái trong từ xuất hiện hết và Người không bấm chuông trả lời ngay từ cần đoán, Người vẫn là người chiến thắng. Ngược lại, Máy chiến thắng.
- Nếu chọn Chế độ Thoát game: Màn hình sẽ hiện ra như sau:
![image](https://user-images.githubusercontent.com/81974069/117326923-5189c480-aebc-11eb-8e2b-622d6238bab5.png)
        Khi đó, game kết thúc và người chơi bấm phím bất kì để thoát game.

# IV: Các hàm sử dụng trong Hangman Olympia:
1. int countLines(vector <string> words): Là hàm đếm số từ trong file từ có sẵn (dùng để chia rand khi chọn từ). Hàm nhập vào một mảng xâu gồm các từ, và trả về số lượng từ dưới dạng số nguyên (int).
2. string getWord(): Là hàm lựa chọn một từ trong file từ có sẵn. Hàm trả về một từ được chọn ngẫu nhiên từ file.
3. string runAI(): Hàm này sử dụng để Máy chọn từ một cách tự động (chỉ dùng ở chế độ 2).
4. void endGame(): Hàm này dùng để làm thủ tục kết thúc game.
5. string updateWord(string word, vector <int> characterLocations, char to_update): Là hàm dùng để cập nhật từ nếu đoán đúng. Hàm này cập nhật kí tự đoán đúng bằng cách thay dấu "-" ở vị trí (characterLocations) dưới dạng mảng gồm một hoặc nhiều số nguyên (tùy vào số lần xuất hiện của kí tự trong từ) bằng kí tự đó (to_update).
6. bool has_only_alpha(string word): Là hàm dùng để báo sai khi kí tự được nhập vào từ (word) là một kí tự khác chữ (trừ phím 1 ở chế độ 2 là phím bấm chuông trả lời từ cần đoán).
7. vector <int> findLocation(string sample, char findIt): Hàm này giúp tạo mảng xác định vị trí mà kí tự (findIt) được đoán đúng xuất hiện trong từ (sample).
8. void toLower(string& word): Hàm này giúp chuẩn hóa kí tự hoa thành kí tự thường khi nhập vào để đoán từ (word).
9. void printMax(): Hàm giúp chống tràn màn hình.

# V: Hướng dẫn cài đặt: 
- Các bạn download theo link sau: https://github.com/lxduonguetvnu/HangmanOlympia
- Sau đó, các bạn giải nén và vào file main.cpp bằng Code::Blocks 20.03, chọn biểu tượng "Build and run" để chạy chương trình.

# VI: Lời cảm ơn:
Qua file README này, em / mình xin chân thành cảm ơn:
- Hai người thầy đã giúp đỡ em trong việc củng cố kiến thức Lý thuyết và Thực hành trong học phần INT2215 - thầy Lê Quang Hiếu và thầy Nguyễn Thanh Bình.
- Tập thể lớp K65CB, K65C-CLC - những người đã luôn động viên và giải đáp thắc mắc của mình trong những lúc khó khăn nhất trong thời gian triển khai ý tưởng. 
Một lần nữa, xin chân thành cảm ơn mọi người! 
# Thanh Hóa, đêm ngày 6/5/2021
# Lê Xuân Dương

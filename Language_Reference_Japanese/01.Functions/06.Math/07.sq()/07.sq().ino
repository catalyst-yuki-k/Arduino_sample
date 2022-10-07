// 数値の二乗を計算する。
// 書式：sq(x)
// 変数：xは数値。データ型は任意。
// 戻り値：xの二乗。データ型はdouble。
// 注意と警告：
// sq()関数の実装上、括弧の中で他の関数を使用すると、誤った結果を招く可能性があります。
// 以下のコードでは、誤った結果を得ることになります。
int inputSquared = sq(Serial.parseInt());
// その他の操作をsq関数の外に置く
int input = Serial.parseInt();
int inputSquared = sq(input);
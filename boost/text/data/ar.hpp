// Warning! This file is autogenerated.
#ifndef BOOST_TEXT_DATA_AR_HPP
#define BOOST_TEXT_DATA_AR_HPP


namespace boost { namespace text { namespace data { namespace ar {

inline string_view compat_collation_tailoring()
{
    return string_view(
        R"(  
[reorder Arab]
&ت<<ة<<<ﺔ<<<ﺓ
&ي<<ى<<<ﯨ<<<ﯩ<<<ﻰ<<<ﻯ<<<ﲐ<<<ﱝ
  )"
    );
}

inline string_view standard_collation_tailoring()
{
    return string_view(
        R"(  
[reorder Arab]
&[before 2]ت<<‎ة
&[before 2]‎ي‎<<ی<<‎ى
&‎ء<<‎أ<<‎ؤ<<‎إ<<‎ئ<<‎ىٕ<<‎ا
  ‎&ءا‎<<‎آ‎
&[last secondary ignorable]<<<\u064B<<<\u08F0<<<\u08E7<<<\u064C<<<\u08F1
  <<<\u08E8<<<\u064D<<<\u08F2<<<\u08E9<<<\u064E<<<\u08E4<<<\u08F4<<<\u08F5
  <<<\u064F<<<\u08E5<<<\u08FE<<<\u0650<<<\u08E6<<<\u08F6<<<\u0651<<<\u0652
  <<<\u0653<<<\u06DF<<<\u06E1<<<\u065F<<<\u0656<<<\u0657<<<\u0658<<<\u08FF
  <<<\u0659<<<\u065A<<<\u065B<<<\u065C<<<\u065D<<<\u065E<<<\u08F7<<<\u08F8
  <<<\u08FD<<<\u08FB<<<\u08FC<<<\u08F9<<<\u08FA<<<\u0670
&‎'بسم الله الرحمن الرحيم'<<<‎﷽
  ‎&ء‎=ﺀ
  ‎&ا‎=ﺍ‎=ﺎ
  ‎&اكبر‎<<<ﷳ
  ‎&الله‎<<<ﷲ
  ‎&ا\u064B‎=ﴼ‎=ﴽ
  ‎&آ‎=ﺁ‎=ﺂ
  ‎&أ‎=ﺃ‎=ﺄ
  ‎&إ‎=ﺇ‎=ﺈ
  ‎&ب‎=ﺏ‎=ﺐ‎=ﺑ‎=ﺒ
  ‎&بج‎=ﰅ‎=ﲜ
  ‎&بح‎=ﰆ‎=ﲝ
  ‎&بحي‎=ﷂ
  ‎&بخ‎=ﰇ‎=ﲞ
  ‎&بخي‎=ﶞ
  ‎&بر‎=ﱪ
  ‎&بز‎=ﱫ
  ‎&بم‎=ﰈ‎=ﱬ‎=ﲟ‎=ﳡ
  ‎&بن‎=ﱭ
  ‎&به‎=ﲠ‎=ﳢ
  ‎&بى‎=ﰉ‎=ﱮ
  ‎&بي‎=ﰊ‎=ﱯ
  ‎&ة‎=ﺓ‎=ﺔ
  ‎&ت‎=ﺕ‎=ﺖ‎=ﺗ‎=ﺘ
  ‎&تج‎=ﰋ‎=ﲡ
  ‎&تجم‎=ﵐ
  ‎&تجى‎=ﶠ
  ‎&تجي‎=ﶟ
  ‎&تح‎=ﰌ‎=ﲢ
  ‎&تحج‎=ﵑ‎=ﵒ
  ‎&تحم‎=ﵓ
  ‎&تخ‎=ﰍ‎=ﲣ
  ‎&تخم‎=ﵔ
  ‎&تخى‎=ﶢ
  ‎&تخي‎=ﶡ
  ‎&تر‎=ﱰ
  ‎&تز‎=ﱱ
  ‎&تم‎=ﰎ‎=ﱲ‎=ﲤ‎=ﳣ
  ‎&تمج‎=ﵕ
  ‎&تمح‎=ﵖ
  ‎&تمخ‎=ﵗ
  ‎&تمى‎=ﶤ
  ‎&تمي‎=ﶣ
  ‎&تن‎=ﱳ
  ‎&ته‎=ﲥ‎=ﳤ
  ‎&تى‎=ﰏ‎=ﱴ
  ‎&تي‎=ﰐ‎=ﱵ
  ‎&ث‎=ﺙ‎=ﺚ‎=ﺛ‎=ﺜ
  ‎&ثج‎=ﰑ
  ‎&ثر‎=ﱶ
  ‎&ثز‎=ﱷ
  ‎&ثم‎=ﰒ‎=ﱸ‎=ﲦ‎=ﳥ
  ‎&ثن‎=ﱹ
  ‎&ثه‎=ﳦ
  ‎&ثى‎=ﰓ‎=ﱺ
  ‎&ثي‎=ﰔ‎=ﱻ
  ‎&ج‎=ﺝ‎=ﺞ‎=ﺟ‎=ﺠ
  ‎&جح‎=ﰕ‎=ﲧ
  ‎&جحى‎=ﶦ
  ‎&جحي‎=ﶾ
  ‎&'جل جلاله'‎<<<ﷻ
  ‎&جم‎=ﰖ‎=ﲨ
  ‎&جمح‎=ﵘ‎=ﵙ
  ‎&جمى‎=ﶧ
  ‎&جمي‎=ﶥ
  ‎&جى‎=ﴁ‎=ﴝ
  ‎&جي‎=ﴂ‎=ﴞ
  ‎&ح‎=ﺡ‎=ﺢ‎=ﺣ‎=ﺤ
  ‎&حج‎=ﰗ‎=ﲩ
  ‎&حجي‎=ﶿ
  ‎&حم‎=ﰘ‎=ﲪ
  ‎&حمى‎=ﵛ
  ‎&حمي‎=ﵚ
  ‎&حى‎=ﳿ‎=ﴛ
  ‎&حي‎=ﴀ‎=ﴜ
  ‎&خ‎=ﺥ‎=ﺦ‎=ﺧ‎=ﺨ
  ‎&خج‎=ﰙ‎=ﲫ
  ‎&خح‎=ﰚ
  ‎&خم‎=ﰛ‎=ﲬ
  ‎&خى‎=ﴃ‎=ﴟ
  ‎&خي‎=ﴄ‎=ﴠ
  ‎&د‎=ﺩ‎=ﺪ
  ‎&ذ‎=ﺫ‎=ﺬ
  ‎&ذ\u0670‎=ﱛ
  ‎&ر‎=ﺭ‎=ﺮ
  ‎&رسول‎<<<ﷶ
  ‎&ر\u0670‎=ﱜ
  ‎&ریال‎<<<﷼
  ‎&ز‎=ﺯ‎=ﺰ
  ‎&س‎=ﺱ‎=ﺲ‎=ﺳ‎=ﺴ
  ‎&سج‎=ﰜ‎=ﲭ‎=ﴴ
  ‎&سجح‎=ﵝ
  ‎&سجى‎=ﵞ
  ‎&سح‎=ﰝ‎=ﲮ‎=ﴵ
  ‎&سحج‎=ﵜ
  ‎&سخ‎=ﰞ‎=ﲯ‎=ﴶ
  ‎&سخى‎=ﶨ
  ‎&سخي‎=ﷆ
  ‎&سر‎=ﴎ‎=ﴪ
  ‎&سم‎=ﰟ‎=ﲰ‎=ﳧ
  ‎&سمج‎=ﵡ
  ‎&سمح‎=ﵟ‎=ﵠ
  ‎&سمم‎=ﵢ‎=ﵣ
  ‎&سه‎=ﳨ‎=ﴱ
  ‎&سى‎=ﳻ‎=ﴗ
  ‎&سي‎=ﳼ‎=ﴘ
  ‎&ش‎=ﺵ‎=ﺶ‎=ﺷ‎=ﺸ
  ‎&شج‎=ﴉ‎=ﴥ‎=ﴭ‎=ﴷ
  ‎&شجي‎=ﵩ
  ‎&شح‎=ﴊ‎=ﴦ‎=ﴮ‎=ﴸ
  ‎&شحم‎=ﵧ‎=ﵨ
  ‎&شحي‎=ﶪ
  ‎&شخ‎=ﴋ‎=ﴧ‎=ﴯ‎=ﴹ
  ‎&شر‎=ﴍ‎=ﴩ
  ‎&شم‎=ﳩ‎=ﴌ‎=ﴨ‎=ﴰ
  ‎&شمخ‎=ﵪ‎=ﵫ
  ‎&شمم‎=ﵬ‎=ﵭ
  ‎&شه‎=ﳪ‎=ﴲ
  ‎&شى‎=ﳽ‎=ﴙ
  ‎&شي‎=ﳾ‎=ﴚ
  ‎&ص‎=ﺹ‎=ﺺ‎=ﺻ‎=ﺼ
  ‎&صح‎=ﰠ‎=ﲱ
  ‎&صحح‎=ﵤ‎=ﵥ
  ‎&صحي‎=ﶩ
  ‎&صخ‎=ﲲ
  ‎&صر‎=ﴏ‎=ﴫ
  ‎&صلعم‎<<<ﷵ
  ‎&صلى‎<<<ﷹ
  ‎&'صلى الله عليه وسلم'‎<<<ﷺ
  ‎&صلے‎<<<ﷰ
  ‎&صم‎=ﰡ‎=ﲳ
  ‎&صمم‎=ﵦ‎=ﷅ
  ‎&صى‎=ﴅ‎=ﴡ
  ‎&صي‎=ﴆ‎=ﴢ
  ‎&ض‎=ﺽ‎=ﺾ‎=ﺿ‎=ﻀ
  ‎&ضج‎=ﰢ‎=ﲴ
  ‎&ضح‎=ﰣ‎=ﲵ
  ‎&ضحى‎=ﵮ
  ‎&ضحي‎=ﶫ
  ‎&ضخ‎=ﰤ‎=ﲶ
  ‎&ضخم‎=ﵯ‎=ﵰ
  ‎&ضر‎=ﴐ‎=ﴬ
  ‎&ضم‎=ﰥ‎=ﲷ
  ‎&ضى‎=ﴇ‎=ﴣ
  ‎&ضي‎=ﴈ‎=ﴤ
  ‎&ط‎=ﻁ‎=ﻂ‎=ﻃ‎=ﻄ
  ‎&طح‎=ﰦ‎=ﲸ
  ‎&طم‎=ﰧ‎=ﴳ‎=ﴺ
  ‎&طمح‎=ﵱ‎=ﵲ
  ‎&طمم‎=ﵳ
  ‎&طمي‎=ﵴ
  ‎&طى‎=ﳵ‎=ﴑ
  ‎&طي‎=ﳶ‎=ﴒ
  ‎&ظ‎=ﻅ‎=ﻆ‎=ﻇ‎=ﻈ
  ‎&ظم‎=ﰨ‎=ﲹ‎=ﴻ
  ‎&ع‎=ﻉ‎=ﻊ‎=ﻋ‎=ﻌ
  ‎&عج‎=ﰩ‎=ﲺ
  ‎&عجم‎=ﵵ‎=ﷄ
  ‎&عليه‎<<<ﷷ
  ‎&عم‎=ﰪ‎=ﲻ
  ‎&عمم‎=ﵶ‎=ﵷ
  ‎&عمى‎=ﵸ
  ‎&عمي‎=ﶶ
  ‎&عى‎=ﳷ‎=ﴓ
  ‎&عي‎=ﳸ‎=ﴔ
  ‎&غ‎=ﻍ‎=ﻎ‎=ﻏ‎=ﻐ
  ‎&غج‎=ﰫ‎=ﲼ
  ‎&غم‎=ﰬ‎=ﲽ
  ‎&غمم‎=ﵹ
  ‎&غمى‎=ﵻ
  ‎&غمي‎=ﵺ
  ‎&غى‎=ﳹ‎=ﴕ
  ‎&غي‎=ﳺ‎=ﴖ
  ‎&ـ\u064B‎=ﹱ
  ‎&ـ\u064E‎=ﹷ
  ‎&ـ\u064E\u0651‎=ﳲ
  ‎&ـ\u064F‎=ﹹ
  ‎&ـ\u064F\u0651‎=ﳳ
  ‎&ـ\u0650‎=ﹻ
  ‎&ـ\u0650\u0651‎=ﳴ
  ‎&ـ\u0651‎=ﹽ
  ‎&ـ\u0652‎=ﹿ
  ‎&ف‎=ﻑ‎=ﻒ‎=ﻓ‎=ﻔ
  ‎&فج‎=ﰭ‎=ﲾ
  ‎&فح‎=ﰮ‎=ﲿ
  ‎&فخ‎=ﰯ‎=ﳀ
  ‎&فخم‎=ﵼ‎=ﵽ
  ‎&فم‎=ﰰ‎=ﳁ
  ‎&فمي‎=ﷁ
  ‎&فى‎=ﰱ‎=ﱼ
  ‎&في‎=ﰲ‎=ﱽ
  ‎&ق‎=ﻕ‎=ﻖ‎=ﻗ‎=ﻘ
  ‎&قح‎=ﰳ‎=ﳂ
  ‎&قلے‎<<<ﷱ
  ‎&قم‎=ﰴ‎=ﳃ
  ‎&قمح‎=ﵾ‎=ﶴ
  ‎&قمم‎=ﵿ
  ‎&قمي‎=ﶲ
  ‎&قى‎=ﰵ‎=ﱾ
  ‎&قي‎=ﰶ‎=ﱿ
  ‎&ك‎=ﻙ‎=ﻚ‎=ﻛ‎=ﻜ
  ‎&كا‎=ﰷ‎=ﲀ
  ‎&كج‎=ﰸ‎=ﳄ
  ‎&كح‎=ﰹ‎=ﳅ
  ‎&كخ‎=ﰺ‎=ﳆ
  ‎&كل‎=ﰻ‎=ﲁ‎=ﳇ‎=ﳫ
  ‎&كم‎=ﰼ‎=ﲂ‎=ﳈ‎=ﳬ
  ‎&كمم‎=ﶻ‎=ﷃ
  ‎&كمي‎=ﶷ
  ‎&كى‎=ﰽ‎=ﲃ
  ‎&كي‎=ﰾ‎=ﲄ
  ‎&ل‎=ﻝ‎=ﻞ‎=ﻟ‎=ﻠ
  ‎&لا‎=ﻻ‎=ﻼ
  ‎&لآ‎=ﻵ‎=ﻶ
  ‎&لأ‎=ﻷ‎=ﻸ
  ‎&لإ‎=ﻹ‎=ﻺ
  ‎&لج‎=ﰿ‎=ﳉ
  ‎&لجج‎=ﶃ‎=ﶄ
  ‎&لجم‎=ﶺ‎=ﶼ
  ‎&لجي‎=ﶬ
  ‎&لح‎=ﱀ‎=ﳊ
  ‎&لحم‎=ﶀ‎=ﶵ
  ‎&لحى‎=ﶂ
  ‎&لحي‎=ﶁ
  ‎&لخ‎=ﱁ‎=ﳋ
  ‎&لخم‎=ﶅ‎=ﶆ
  ‎&لم‎=ﱂ‎=ﲅ‎=ﳌ‎=ﳭ
  ‎&لمح‎=ﶇ‎=ﶈ
  ‎&لمي‎=ﶭ
  ‎&له‎=ﳍ
  ‎&لى‎=ﱃ‎=ﲆ
  ‎&لي‎=ﱄ‎=ﲇ
  ‎&م‎=ﻡ‎=ﻢ‎=ﻣ‎=ﻤ
  ‎&ما‎=ﲈ
  ‎&مج‎=ﱅ‎=ﳎ
  ‎&مجح‎=ﶌ
  ‎&مجخ‎=ﶒ
  ‎&مجم‎=ﶍ
  ‎&مجي‎=ﷀ
  ‎&مح‎=ﱆ‎=ﳏ
  ‎&محج‎=ﶉ
  ‎&محم‎=ﶊ
  ‎&محمد‎<<<ﷴ
  ‎&محي‎=ﶋ
  ‎&مخ‎=ﱇ‎=ﳐ
  ‎&مخج‎=ﶎ
  ‎&مخم‎=ﶏ
  ‎&مخي‎=ﶹ
  ‎&مم‎=ﱈ‎=ﲉ‎=ﳑ
  ‎&ممي‎=ﶱ
  ‎&مى‎=ﱉ
  ‎&مي‎=ﱊ
  ‎&ن‎=ﻥ‎=ﻦ‎=ﻧ‎=ﻨ
  ‎&نج‎=ﱋ‎=ﳒ
  ‎&نجح‎=ﶸ‎=ﶽ
  ‎&نجم‎=ﶗ‎=ﶘ
  ‎&نجى‎=ﶙ
  ‎&نجي‎=ﷇ
  ‎&نح‎=ﱌ‎=ﳓ
  ‎&نحم‎=ﶕ
  ‎&نحى‎=ﶖ
  ‎&نحي‎=ﶳ
  ‎&نخ‎=ﱍ‎=ﳔ
  ‎&نر‎=ﲊ
  ‎&نز‎=ﲋ
  ‎&نم‎=ﱎ‎=ﲌ‎=ﳕ‎=ﳮ
  ‎&نمى‎=ﶛ
  ‎&نمي‎=ﶚ
  ‎&نن‎=ﲍ
  ‎&نه‎=ﳖ‎=ﳯ
  ‎&نى‎=ﱏ‎=ﲎ
  ‎&ني‎=ﱐ‎=ﲏ
  ‎&ه‎=ﻩ‎=ﻪ‎=ﻫ‎=ﻬ
  ‎&هج‎=ﱑ‎=ﳗ
  ‎&هم‎=ﱒ‎=ﳘ
  ‎&همج‎=ﶓ
  ‎&همم‎=ﶔ
  ‎&هى‎=ﱓ
  ‎&هي‎=ﱔ
  ‎&ه\u0670‎=ﳙ
  ‎&و‎=ﻭ‎=ﻮ
  ‎&وسلم‎<<<ﷸ
  ‎&ؤ‎=ﺅ‎=ﺆ
  ‎&ى‎=ﯨ‎=ﯩ‎=ﻯ‎=ﻰ
  ‎&ى\u0670‎=ﱝ‎=ﲐ
  ‎&ي‎=ﻱ‎=ﻲ‎=ﻳ‎=ﻴ
  ‎&يج‎=ﱕ‎=ﳚ
  ‎&يجي‎=ﶯ
  ‎&يح‎=ﱖ‎=ﳛ
  ‎&يحي‎=ﶮ
  ‎&يخ‎=ﱗ‎=ﳜ
  ‎&ير‎=ﲑ
  ‎&يز‎=ﲒ
  ‎&يم‎=ﱘ‎=ﲓ‎=ﳝ‎=ﳰ
  ‎&يمم‎=ﶜ‎=ﶝ
  ‎&يمي‎=ﶰ
  ‎&ين‎=ﲔ
  ‎&يه‎=ﳞ‎=ﳱ
  ‎&يى‎=ﱙ‎=ﲕ
  ‎&يي‎=ﱚ‎=ﲖ
  ‎&ئ‎=ﺉ‎=ﺊ‎=ﺋ‎=ﺌ
  ‎&ئا‎=ﯪ‎=ﯫ
  ‎&ئج‎=ﰀ‎=ﲗ
  ‎&ئح‎=ﰁ‎=ﲘ
  ‎&ئخ‎=ﲙ
  ‎&ئر‎=ﱤ
  ‎&ئز‎=ﱥ
  ‎&ئم‎=ﰂ‎=ﱦ‎=ﲚ‎=ﳟ
  ‎&ئن‎=ﱧ
  ‎&ئه‎=ﲛ‎=ﳠ
  ‎&ئو‎=ﯮ‎=ﯯ
  ‎&ئى‎=ﯹ‎=ﯺ‎=ﯻ‎=ﰃ‎=ﱨ
  ‎&ئي‎=ﰄ‎=ﱩ
  ‎&ئۆ‎=ﯲ‎=ﯳ
  ‎&ئۇ‎=ﯰ‎=ﯱ
  ‎&ئۈ‎=ﯴ‎=ﯵ
  ‎&ئې‎=ﯶ‎=ﯷ‎=ﯸ
  ‎&ئە‎=ﯬ‎=ﯭ
  ‎&\u064B‎=ﹰ
  ‎&\u064C‎=ﹲ
  ‎&\u064C\u0651‎=ﱞ
  ‎&\u064D‎=ﹴ
  ‎&\u064D\u0651‎=ﱟ
  ‎&\u064E‎=ﹶ
  ‎&\u064E\u0651‎=ﱠ
  ‎&\u064F‎=ﹸ
  ‎&\u064F\u0651‎=ﱡ
  ‎&\u0650‎=ﹺ
  ‎&\u0650\u0651‎=ﱢ
  ‎&\u0651‎=ﹼ
  ‎&\u0651\u0670‎=ﱣ
  ‎&\u0652‎=ﹾ
  ‎&ٱ‎=ﭐ‎=ﭑ
  ‎&ٹ‎=ﭦ‎=ﭧ‎=ﭨ‎=ﭩ
  ‎&ٺ‎=ﭞ‎=ﭟ‎=ﭠ‎=ﭡ
  ‎&ٻ‎=ﭒ‎=ﭓ‎=ﭔ‎=ﭕ
  ‎&پ‎=ﭖ‎=ﭗ‎=ﭘ‎=ﭙ
  ‎&ٿ‎=ﭢ‎=ﭣ‎=ﭤ‎=ﭥ
  ‎&ڀ‎=ﭚ‎=ﭛ‎=ﭜ‎=ﭝ
  ‎&ڃ‎=ﭶ‎=ﭷ‎=ﭸ‎=ﭹ
  ‎&ڄ‎=ﭲ‎=ﭳ‎=ﭴ‎=ﭵ
  ‎&چ‎=ﭺ‎=ﭻ‎=ﭼ‎=ﭽ
  ‎&ڇ‎=ﭾ‎=ﭿ‎=ﮀ‎=ﮁ
  ‎&ڈ‎=ﮈ‎=ﮉ
  ‎&ڌ‎=ﮄ‎=ﮅ
  ‎&ڍ‎=ﮂ‎=ﮃ
  ‎&ڎ‎=ﮆ‎=ﮇ
  ‎&ڑ‎=ﮌ‎=ﮍ
  ‎&ژ‎=ﮊ‎=ﮋ
  ‎&ڤ‎=ﭪ‎=ﭫ‎=ﭬ‎=ﭭ
  ‎&ڦ‎=ﭮ‎=ﭯ‎=ﭰ‎=ﭱ
  ‎&ک‎=ﮎ‎=ﮏ‎=ﮐ‎=ﮑ
  ‎&ڭ‎=ﯓ‎=ﯔ‎=ﯕ‎=ﯖ
  ‎&گ‎=ﮒ‎=ﮓ‎=ﮔ‎=ﮕ
  ‎&ڱ‎=ﮚ‎=ﮛ‎=ﮜ‎=ﮝ
  ‎&ڳ‎=ﮖ‎=ﮗ‎=ﮘ‎=ﮙ
  ‎&ں‎=ﮞ‎=ﮟ
  ‎&ڻ‎=ﮠ‎=ﮡ‎=ﮢ‎=ﮣ
  ‎&ھ‎=ﮪ‎=ﮫ‎=ﮬ‎=ﮭ
  ‎&ہ‎=ﮦ‎=ﮧ‎=ﮨ‎=ﮩ
  ‎&ۅ‎=ﯠ‎=ﯡ
  ‎&ۆ‎=ﯙ‎=ﯚ
  ‎&ۇ‎=ﯗ‎=ﯘ
  ‎&ۇٴ‎=ﯝ
  ‎&ۈ‎=ﯛ‎=ﯜ
  ‎&ۉ‎=ﯢ‎=ﯣ
  ‎&ۋ‎=ﯞ‎=ﯟ
  ‎&ی‎=ﯼ‎=ﯽ‎=ﯾ‎=ﯿ
  ‎&ې‎=ﯤ‎=ﯥ‎=ﯦ‎=ﯧ
  ‎&ے‎=ﮮ‎=ﮯ
  ‎&ۓ‎=ﮰ‎=ﮱ
  ‎&ۀ‎=ﮤ‎=ﮥ
  )"
    );
}


}}}}

#endif
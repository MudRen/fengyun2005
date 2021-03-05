
#define        YUN_LvNeed        20
// 运用技能需要的等级(cmd: yun)

#define        PFM_LvNeed        40
// 绝招需要的技能等级(cmd: pfm)

int time,deng,DENG_AMOUNT=7,MAX_HP=500,DENG_TIME=400;  // 标准设置为 300

// time,灯的数量（7个），玩家进入游戏时最大气，每个灯熄灭的时限（秒）
// 与下面之 extend_deng 值联系，游戏总时间为 deng_time 值的 10 倍。

int EXTEND_DENG = 3;

// 延长游戏时间。当玩家进入游戏时，先默算这几轮；完了再开始灭灯。

string long_color=""HIC"",wait_over="no";
string longs="这是一个四四方方的小盒子，盒盖透明，你能见到内里有"+chinese_number(DENG_AMOUNT)+"个小点在散发着微弱的光芒。\n";

string *context1=({
    " ",
    "风",
    "我们轻灵而飘忽的国度",
    "它的宝物有着天马之身 伸展之双翼",
    "当你寻得它们",
    "你将能够重见风之国度",
    "你将能够领会它的启示。",
});

string *context2=({
    " ",
    "雨",
    "我们柔和而聪慧的国度",
    "它的宝物有着晶莹之泪 敏慧之心 和 灵巧之手",
    "当你寻得它们",
    "你将能够重见雨之国度",
    "你将能够领会它的启示。",
});

string *context3=({
    " ",
    "雷",
    "我们勇敢而强壮的国度",
    "它的宝物有着神力之剑 点缀之石 和 容忍之鞘",
    "当你寻得它们",
    "你将能够重见雷之国度",
    "你将能够领会它的启示。",
});

string *context4=({
    " ",
    "电",
    "我们勤劳而耐心的国度",
    "它的宝物最是难寻",
    "它时而隐藏  时而真现",
    "但它总改变不了自身的荧光。",
    "当你见到一颗宝石的模样",
    "也许那就是你要寻找之物",
    "三颗宝石  将带领你去体会",
    "古老的国度的秘密。",
});

void sing_song(int i, object me);
string singing="no";
string *songs;
int about_me_obj=0; // 0，表示未发放本人相关物品。
int start_checking=0; // 0，表示未启动检测程序。

void fighting();
void healing( object me );
mapping can_use_pfm( string fight_use, object me, object target );



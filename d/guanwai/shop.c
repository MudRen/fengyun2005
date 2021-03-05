inherit ROOM;

void create()
{
	set("short", "鹰记商号");
	set("long", @LONG
鹰记一向是信用卓著，生意鼎盛的商号。虽然现在换了新东家，不过生意还是
如以往一样热闹，从藏东运来的藏香，从关内运来的瓷器和丝缎，从打箭炉运来的
茶砖，无论什么，只要是件值钱的东西，都可以在这里自由买卖。柜台上放著一块
牌子（ＳＩＧＮ）。
LONG
	);
      	
	set("item_desc", ([
		"sign": @TEXT
本商号财力雄厚。客倌可以在这里：
convert     兑换钱币。
withdraw    提取存款。
deposit     存入钱币。
balance     察寻存款。
loan        向钱庄借钱。
pawn	    典当。
sell	    卖断。
value	    估价。
redeem	    赎回。
TEXT
	]) );
	set("exits", ([
		"west" : __DIR__"octo15",
	]));
        set("objects", ([
                __DIR__"npc/hu": 1, 
		__DIR__"npc/petowner" : 1,
		]));
	set("coor/x",40);
	set("coor/y",30);
	set("coor/z",0);
	setup();

}
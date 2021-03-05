inherit ROOM;

void create()
{
	set("short", "冥府钱庄");
	set("long", @LONG
中原南宫世家，家财万贯，产业不可胜数，这一切都是南宫大在七十年前创下
的，然而钱财再多、势力再大，也留不住勾魂小鬼的脚步，只是这南宫大不知使了
些什么手段，或是花了多少银子，竟然在这枉死城里也开起了一家钱庄，而这钱庄
竟然与中原的还是相通的。。。。可见阴间阳间，有气没气，最硬通的还是票子。
钱庄中央有一红木柜台，半人多高，上有牌（ｓｉｇｎ）一块。

                [37m【南宫钱庄冥府分行】
[32m
LONG
	);
	set("no_fight", 1);	
	set("no_meal","你忽然发现口中的食物饮水成了苦涩的浊泥，赶快哇哇地吐了出来。\n");
	set("exits", ([
        	"northeast"      : __DIR__"pingan",
	]) );
        set("item_desc", ([
                "sign": @TEXT
这里是钱庄，目前我们提供的服务有：

convert     兑换钱币
withdraw    提取存款
deposit     存入钱币
balance     查询存款数额
loan	    向钱庄借钱
transfer    直接转帐

TEXT
        ]) );

	set("objects", ([
		__DIR__"npc/bankowner" : 1,

			]) );

	set("coor/x",-40);
	set("coor/y",-80);
	set("coor/z",-190);
	set("no_fight",1);
	setup();
}

inherit ROOM;
void create()
{
        set("short", "黑庙");
        set("long", @LONG
屋子里没有别的颜色，只有黑！连夕阳照进来，都变成一种不吉祥的死灰色。
黑色的神幔低垂，没有人能看得见里面供奉的是什么神祠。神案上有把刀，刀鞘
漆黑，刀柄漆黑。地下立着一块牌子（sign），你真的想读一读它（look sign）！
LONG
        );
        set("exits", ([ 
  		"northwest" : __DIR__"sichou5",
           	"southeast" : AREA_QUICKSAND"skyroad3",
	]));
        set("item_desc", ([
                "sign": @TEXT

			从此向西北，意图杀人者死！

牌子下面有行小字：过了此庙，凡是在玩家身上用KILL的都会受到＂边塞双鹰＂
的围杀！牌子再下有两个签名：
			断翅金鹰 古丽娜
        		双头秃鹰 阿里木
TEXT,
                "刀": "刀深深地插在刀鞘中，只露出漆黑的刀柄，刀鞘又深深地插入神案中。\n",
		"blade" : "刀深深地插在刀鞘中，只露出漆黑的刀柄，刀鞘又深深地插入神案中。\n",
        ]) );
        set("objects", ([
//	        __DIR__"npc/furen" : 1,
        ]) );
        
        
	set("NONPC",1);
        set("valid_startroom", 1);
	set("coor/x",120);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
}

/*
void init()
{
	add_action("do_shake","shake");
}
int do_shake(string arg)
{
	object ob;
	if(arg == "刀" || arg == "blade")
	{
	message_vision("$N抓住漆黑的刀柄，用力摇了摇！\n",this_player());	
	if(ob=(present("old woman",this_object())))
		message_vision("$N看了$n一眼，道：好！想帮我报仇？！去杀了那个＂不带刀的人＂\n",ob,
		this_player());
	return 1;
	}
	else
	return 0;

}
*/
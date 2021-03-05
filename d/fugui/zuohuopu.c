inherit ROOM;

void create()
{
	set("short", "杂货铺");

	set("long", @LONG
这是一家小小的杂货铺，四周大箱小箱堆满了一地，都是一些日常用品。韩掌
柜懒洋洋地坐在一只椅子上，招呼着过往行人。据说，掌柜的当初也是有些来头的
江湖人物，绰号叫什么“一阵风”来着。因此私底下他也卖一些贵重的东西。摊上
立着一块招牌（ｓｉｇｎ）。
LONG);


	set("type","house");
	set("indoors", "fugui");
	set("exits",([
		"east":__DIR__"xiaojie2",
	]) );
	set("item_desc", ([
		"sign": @TEXT
    近期治安不好，山西土匪横行。
    本店难以进货，暂停营业。
    不便之处，请各位街坊谅解。

TEXT
	]));
		
	set("objects",([
		__DIR__"npc/zhanggui":1,
	]));

	set("coor/x",10);
	set("coor/y",100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

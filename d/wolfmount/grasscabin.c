inherit ROOM;

void create()
{
	set("short", "草堂");

	set("long", @LONG
一间很小的草堂，空空地什么也没有，但却打扫地异常干净，似乎连一粒尘土
都没有。地上端端正正放着一个蒲团，斜坐着位白发老者，背对著你，仿佛在看一
卷图。  
LONG);

	set("type","house");
       set("indoors", "wolfmount");
	set("exits",([
		"out":__DIR__"flowers",
		"south":__DIR__"shuaiyi",
	]) );
	set("objects",([
     		__DIR__"npc/buzhan":1,
    	]) ); 
	set("coor/x",40);
	set("coor/y",-90);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}

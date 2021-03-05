inherit ROOM;

void create()
{
	set("short", "洞口");

	set("long", @LONG
路至尽头，便是神秘山洞的洞口，刺鼻的腥气愈发令人窒息，洞口旁一块木牌
歪倒在地，你凑上去擦去木牌上的泥垢，只见上面模模糊糊刻着『洞中恶蟒袭人，
勿入！切切』云云。
LONG);
	set("outdoors", "fugui");
	set("type","mountain");
	set("exits",([
        	"enter":__DIR__"shandong",
		"southwest":__DIR__"senling4",
	]) );

	set("coor/x",-10);
	set("coor/y",270);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}

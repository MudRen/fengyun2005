inherit ROOM;

void create()
{
      set("short", "江心");

	set("long", @LONG
雅鲁藏布江咆哮汹涌，流至此地，便是水流最为湍急之处。两旁峭壁陡立，江
水就象嵌在巨斧劈开的石缝里，急流奔腾，声震山峡。更有一处山崖突入江心，万
马奔腾的江水，象发怒的雄狮，如脱疆狂奔的野马，汹涌澎湃，奔流而下到这里突
然变成千万个漩涡，水面陡然下降，波涛汹涌，浪花四溅。仔细看去，漩涡中心似
有几块黑色的礁石突起，屹立不动。（未完工地区）
LONG);

         set("exits", ([ 
		]));
        set("outdoors", "guanwai");

		
        set("objects", ([
        ]) ); 
		set("coor/x",150);
		set("coor/y",-490);
		set("coor/z",0);
		set("objects", ([
       ]) );

		setup();
		replace_program(ROOM);
}

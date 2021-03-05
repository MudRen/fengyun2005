
inherit ROOM;

void create()
{
    set("short", "大明湖");
	set("long", @LONG
“三面荷花四面柳，一城山色半城湖”，名动天下的大明湖为济南名胜之首，
湖光柳色，旖旎动人。沿着湖边漫步，风中柳枝纤瘦，楚楚可怜；斜阳残照，映得
半湖泛红。碧琉璃般的湖面上烟水蒙蒙，泛舟湖上，似乎所有愁情烦事都可一一抛
去。抬眼望去，绿草坪、垂杨柳，红水波中烟云缭绕的山峦隐约可见。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"street2",
  "northeast" : __DIR__"road1",
  "southeast" : __DIR__"bridge1",
]));
        set("objects", ([
        __DIR__"npc/surong" : 1,
                        ]) );
        set("resource/water",1);
        set("liquid", ([
        "container":"大明湖",
        "name":	"大明湖水",
        		]));
        	
    set("outdoors", "jinan");
	set("coor/x",20);
	set("coor/y",80);
	set("coor/z",0);
	setup();
}

/*
void init()
{
	string msg;
	msg = "asfsdfsa";
	message_vision(msg,this_player());
	message_vision(capitalize(msg),this_player());
}

*/

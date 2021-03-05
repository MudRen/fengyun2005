inherit ROOM;
void create()
{
        set("short", "火焰山");
        set("long", @LONG
火焰山有十多个山头，均呈橘红色，在烈日的照耀下，宛若燃烧着的熊熊大火，
故名火焰山。对于此山的形成有个古老的传说：古时候，天山有一条恶龙经常吃童
男童女。一位叫哈拉和卓的青年决心降伏恶龙。他手执宝剑，与恶龙激战三天三夜，
终于腰斩了恶龙，并把恶龙斩成十多截。死龙不再颤动，变成一座红山，被斩开处
变成了火焰山中的峡谷。
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"butao",
  "southeast" : __DIR__"sichou4",
  "east" : __DIR__"qianfo",
]));
        set("objects", ([
        __DIR__"npc/huwaiter" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

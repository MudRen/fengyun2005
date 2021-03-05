inherit ROOM;
void create()
{
    set("short", "贡院");
    set("long", @LONG
大门五楹，往里有二门五楹、龙门、明远楼、致公堂、内龙门、聚奎堂、会经
堂、十八房等处。风云城人才辈出，凡是有志于宦途的年青人都要在这里通过考试。
乡试多在八月举行，叫"秋闱"。榜首之人便可参加每隔三年举行一次的会试，通常
在三月，叫"春闱"。会试共考三场，每场考三天。考取的参加皇上主持的殿试，殿
试中了便成进士，前三名即为状元、榜眼、探花。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"jidijie",
      ]));
    set("objects", ([
	__DIR__"npc/kaoguan" : 1,
	__DIR__"npc/student" : 3,
      ]) );

    set("coor/x",-20);
    set("coor/y",100);
    set("coor/z",0);
    set("map","fynorth");
    setup();
}

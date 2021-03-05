// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "庵堂");
        set("long", @LONG
庵堂正中供奉着一尊观音像，四周垂有帷幔，一张长几上供奉着鲜花和水果，
中间是一香炉，里面点着三根香，淡青色的烟袅袅婷婷徘徊在屋内的梁柱之间，屋
内的一切都似笼上了一层薄纱。桌前的地上摆着几个蒲团，旁边放着几个木鱼。       
LONG
        );
	set("exits", ([ 
    	"north" : __DIR__"yard",  
	]));
    	set("objects", ([
        	__DIR__"npc/nun" : 2,
    		__DIR__"npc/master": 1,
    	]) );
    	set("indoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-40);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}

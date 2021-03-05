// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "车崩狱");
        set("long", @LONG
恰似战国时候的五马分尸，也称车裂，育两种，一种是将罪犯四肢套在五辆车
车辕上，然后众车背到而驰，一种是以千斤战车碾轧人身，就算铁打金刚也会分成
数段。此刑在人间早以废除不用，不想在地狱尚能一见，此刑酷烈，想来此间犯人
的罪必大到极点。再往下又是一类犯人了，又当如何呢？
LONG
        );
        set("exits", ([
		"up" : __DIR__"zhuidao",
		"down" : __DIR__"hanbing",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-90);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 

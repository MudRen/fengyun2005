inherit __DIR__"tutor";
#include <ansi.h>
void create()
{
        set_name("屏风上的草书", ({ "pingfeng","屏风", "screen" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "屏风上用行草题了一首词。\n"+YEL" 
             纤云弄巧，飞星传恨，
             银汉迢迢暗度。
             金风玉露一相逢，
             便胜却人间无数。
             
             柔情似水，佳期如梦，
             忍顾鹊桥归路。
             两情若是久长时，
             又岂在朝朝暮暮。\n" NOR"\n\n     笔力潇洒中带有绵绵之意，暗合流星飞逝的意境。\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "throwing");
 		set("teaching_limit", 400);
 	}
 	
 }

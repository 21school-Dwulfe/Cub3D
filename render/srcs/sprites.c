// void draw_sprite(Sprite &sprite, FrameBuffer &fb, Player &player, Texture &tex_sprites) {
//     // абсолютное направление от игрока до спрайта (в радианах)
//     float sprite_dir = atan2(sprite.y - player.y, sprite.x - player.x);
//     // удаление лишних оборотов
//     while (sprite_dir - player.a >  M_PI) sprite_dir -= 2*M_PI; 
//     while (sprite_dir - player.a < -M_PI) sprite_dir += 2*M_PI;

//     // расстояние от игрока до спрайта
//     float sprite_dist = std::sqrt(pow(player.x - sprite.x, 2) + pow(player.y - sprite.y, 2)); 
//     size_t sprite_screen_size = std::min(2000, static_cast<int>(fb.h/sprite_dist));
//     // не забывайте, что 3D вид занимает только половину кадрового буфера,
//     // таким образом, fb.w/2 для ширины экрана
//     int h_offset = (sprite_dir - player.a)*(fb.w/2)/(player.fov) + (fb.w/2)/2 - sprite_screen_size/2;
//     int v_offset = fb.h/2 - sprite_screen_size/2;

//     for (size_t i=0; i<sprite_screen_size; i++) {
//         if (h_offset+int(i)<0 || h_offset+i>=fb.w/2) continue;
//         for (size_t j=0; j<sprite_screen_size; j++) {
//             if (v_offset+int(j)<0 || v_offset+j>=fb.h) continue;
//             fb.set_pixel(fb.w/2 + h_offset+i, v_offset+j, pack_color(0,0,0));
//         }
//     }
// }
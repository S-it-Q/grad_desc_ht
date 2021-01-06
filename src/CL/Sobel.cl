__constant sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE |
                               CLK_ADDRESS_CLAMP_TO_EDGE |
                               CLK_FILTER_NEAREST;
                    
__kernel void sobel(read_only image2d_t src, write_only image2d_t dst)
{
    int2 coord = (int2)(get_global_id(0), get_global_id(1));
    int width = get_image_width(dst);

    if (coord.x >= width) {
        return;
    }
}
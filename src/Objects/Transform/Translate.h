#pragma once

#include "Interfaces/IHittable.h"


class Translate : public IHittable {
private:
    // Data
    std::shared_ptr<IHittable> _obj = nullptr;
    Vec3 _offset = Vec3(0);

public:
    explicit Translate(const std::shared_ptr<IHittable> &obj, const Vec3 &displacement) NOEXCEPT;

    virtual std::shared_ptr<IHittable> deep_copy() const NOEXCEPT override;

    virtual bool hit(RandomGenerator &rng, const Ray &r, const rreal t_min, const rreal t_max, HitRecord &rec) const NOEXCEPT override;
    virtual bool bounding_box(const rreal t0, const rreal t1, AABB &output_box) const NOEXCEPT override;
};
